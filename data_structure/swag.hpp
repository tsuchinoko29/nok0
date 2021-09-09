#include <cassert>
#include <functional>
#include <stack>
#include <vector>

template <class S, S (*op)(S, S), S (*e)()>
struct sliding_window_aggregation {
	static const size_t inf = 1e9;

public:
	sliding_window_aggregation(size_t size = inf) : sz(size), front_stack(), back_stack() {}

	bool empty() const { return front_stack.empty() and back_stack.empty(); }

	size_t size() const { return front_stack.size() + back_stack.size(); }

	void resize(size_t x) { sz = x; }

	void pop() {
		assert(!empty());
		if(front_stack.empty()) {
			front_stack.emplace(back_stack.top().val, back_stack.top().val);
			back_stack.pop();
			while(!back_stack.empty()) {
				S tmp = op(back_stack.top().val, front_stack.top().sum);
				front_stack.emplace(back_stack.top().val, tmp);
				back_stack.pop();
			}
		}
		front_stack.pop();
	}

	S fold_all() {
		if(sz != inf) {
			while(size() > sz) pop();
		}
		if(empty()) return e();
		if(front_stack.empty())
			return back_stack.top().sum;
		else if(back_stack.empty())
			return front_stack.top().sum;
		else
			return op(front_stack.top().sum, back_stack.top().sum);
	}

	void push(const S x) {
		if(back_stack.empty())
			back_stack.emplace(x, x);
		else {
			S s = op(back_stack.top().sum, x);
			back_stack.emplace(x, s);
		}
	}

private:
	struct node {
		S val, sum;
		node(const S &val, const S &sum) : val(val), sum(sum) {}
	};

	std::stack<node> front_stack, back_stack;
	size_t sz;
};
