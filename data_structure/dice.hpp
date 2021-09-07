#include <cassert>
#include <iostream>
#include <vector>

struct dice {
public:
	int f, u, b, d, r, l;
	dice(int f_, int b_, int u_, int d_, int r_, int l_)
	  : f(f_), b(b_), u(u_), d(d_), r(r_), l(l_) {}
	dice()
	  : f(3), b(4), u(1), d(6), r(5), l(2) {}

	void rotate(int dir) {
		assert(0 <= dir and dir < 6);
		dice ret(*this);
		switch(dir) {
			case 0:
				ret.f = this->u, ret.u = this->b, ret.b = this->d, ret.d = this->f;
				break;
			case 1:
				ret.d = this->r, ret.l = this->d, ret.u = this->l, ret.r = this->u;
				break;
			case 2:
				ret.f = this->d, ret.u = this->f, ret.b = this->u, ret.d = this->b;
				break;
			case 3:
				ret.d = this->l, ret.l = this->u, ret.u = this->r, ret.r = this->d;
				break;
			case 4:
				ret.f = this->l, ret.l = this->b, ret.b = this->r, ret.r = this->f;
				break;
			case 5:
				ret.f = this->r, ret.l = this->f, ret.b = this->l, ret.r = this->b;
				break;
			default:
				break;
		}
		*this = ret;
	}

	void rotate_f() { rotate(0); }
	void rotate_r() { rotate(1); }
	void rotate_b() { rotate(2); }
	void rotate_l() { rotate(3); }
	void rotate_ccw() { rotate(4); }
	void rotate_cw() { rotate(5); }

	std::vector<dice> make_dice() {
		std::vector<dice> ret;
		for(int i = 0; i < 6; i++) {
			dice d(*this);
			if(i == 1) d.rotate_f();
			if(i == 2) d.rotate_b();
			if(i == 3) d.rotate_f(), d.rotate_f();
			if(i == 4) d.rotate_ccw();
			if(i == 5) d.rotate_cw();
			for(int j = 0; j < 4; j++) {
				ret.emplace_back(d);
				d.rotate_r();
			}
		}
		return ret;
	}

	int operator[](int k) {
		assert(0 <= k and k < 6);
		if(k == 0)
			return this->f;
		else if(k == 1)
			return this->r;
		else if(k == 2)
			return this->b;
		else if(k == 3)
			return this->l;
		else if(k == 4)
			return this->u;
		else
			return this->d;
	}

	void dbg() {
		std::cout << "{";
		std::cout << " f: " << this->f;
		std::cout << " b: " << this->b;
		std::cout << " u: " << this->u;
		std::cout << " d: " << this->d;
		std::cout << " r: " << this->r;
		std::cout << " l: " << this->l;
		std::cout << " }\n";
	}
};
