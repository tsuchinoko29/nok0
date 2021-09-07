#include <functional>
#include <string>
#include <vector>

template <int char_size = 26, int margin = 'a'>
struct Trie {
private:
	struct Node {
		std::vector<int> nxt, accept;
		int exist;
		Node() : exist(0), nxt(char_size, -1) {}
	};
	std::vector<Node> nodes;
	int root;

	void update_direct(const int node, const int id) {
		nodes[node].accept.push_back(id);
	}

	void update_child(const int node, const int child, const int id) {
		++nodes[node].exist;
	}

	void add(const std::string &s, const int str_index, const int node_index, const int id) {
		if(str_index == s.length())
			update_direct(node_index, id);
		else {
			const int c = s[str_index] - margin;
			if(nodes[node_index].nxt[c] == -1) {
				nodes[node_index].nxt[c] = nodes.size();
				nodes.push_back(Node());
			}
			add(s, str_index + 1, nodes[node_index].nxt[c], id);
			update_child(node_index, nodes[node_index].nxt[c], id);
		}
	}

	void query(const std::string &s, const std::function<void(int)> &f, int str_index, int node_index) {
		for(auto &idx : nodes[node_index].accept) f(idx);
		if(str_index == s.length()) {
			return;
		} else {
			const int c = s[str_index] - margin;
			if(nodes[node_index].nxt[c] == -1) return;
			query(s, f, str_index + 1, nodes[node_index].nxt[c]);
		}
	}

public:
	Trie() : root(0) {
		nodes.push_back(Node());
	}

	void add(const std::string &s) {
		add(s, 0, 0, nodes[0].exist);
	}

	void query(const std::string &s, const std::function<void(int)> &f) {
		query(s, f, 0, 0);
	}

	int count() const { return (nodes[0].exist); }

	int size() const { return ((int)nodes.size()); }
};
