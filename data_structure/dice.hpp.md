---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/dice.hpp\"\n#include <cassert>\n#include\
    \ <iostream>\n#include <vector>\n\nstruct dice {\npublic:\n\tint f, u, b, d, r,\
    \ l;\n\tdice(int f_, int b_, int u_, int d_, int r_, int l_)\n\t  : f(f_), b(b_),\
    \ u(u_), d(d_), r(r_), l(l_) {}\n\tdice()\n\t  : f(3), b(4), u(1), d(6), r(5),\
    \ l(2) {}\n\n\tvoid rotate(int dir) {\n\t\tassert(0 <= dir and dir < 6);\n\t\t\
    dice ret(*this);\n\t\tswitch(dir) {\n\t\t\tcase 0:\n\t\t\t\tret.f = this->u, ret.u\
    \ = this->b, ret.b = this->d, ret.d = this->f;\n\t\t\t\tbreak;\n\t\t\tcase 1:\n\
    \t\t\t\tret.d = this->r, ret.l = this->d, ret.u = this->l, ret.r = this->u;\n\t\
    \t\t\tbreak;\n\t\t\tcase 2:\n\t\t\t\tret.f = this->d, ret.u = this->f, ret.b =\
    \ this->u, ret.d = this->b;\n\t\t\t\tbreak;\n\t\t\tcase 3:\n\t\t\t\tret.d = this->l,\
    \ ret.l = this->u, ret.u = this->r, ret.r = this->d;\n\t\t\t\tbreak;\n\t\t\tcase\
    \ 4:\n\t\t\t\tret.f = this->l, ret.l = this->b, ret.b = this->r, ret.r = this->f;\n\
    \t\t\t\tbreak;\n\t\t\tcase 5:\n\t\t\t\tret.f = this->r, ret.l = this->f, ret.b\
    \ = this->l, ret.r = this->b;\n\t\t\t\tbreak;\n\t\t\tdefault:\n\t\t\t\tbreak;\n\
    \t\t}\n\t\t*this = ret;\n\t}\n\n\tvoid rotate_f() { rotate(0); }\n\tvoid rotate_r()\
    \ { rotate(1); }\n\tvoid rotate_b() { rotate(2); }\n\tvoid rotate_l() { rotate(3);\
    \ }\n\tvoid rotate_ccw() { rotate(4); }\n\tvoid rotate_cw() { rotate(5); }\n\n\
    \tstd::vector<dice> make_dice() {\n\t\tstd::vector<dice> ret;\n\t\tfor(int i =\
    \ 0; i < 6; i++) {\n\t\t\tdice d(*this);\n\t\t\tif(i == 1) d.rotate_f();\n\t\t\
    \tif(i == 2) d.rotate_b();\n\t\t\tif(i == 3) d.rotate_f(), d.rotate_f();\n\t\t\
    \tif(i == 4) d.rotate_ccw();\n\t\t\tif(i == 5) d.rotate_cw();\n\t\t\tfor(int j\
    \ = 0; j < 4; j++) {\n\t\t\t\tret.emplace_back(d);\n\t\t\t\td.rotate_r();\n\t\t\
    \t}\n\t\t}\n\t\treturn ret;\n\t}\n\n\tint operator[](int k) {\n\t\tassert(0 <=\
    \ k and k < 6);\n\t\tif(k == 0)\n\t\t\treturn this->f;\n\t\telse if(k == 1)\n\t\
    \t\treturn this->r;\n\t\telse if(k == 2)\n\t\t\treturn this->b;\n\t\telse if(k\
    \ == 3)\n\t\t\treturn this->l;\n\t\telse if(k == 4)\n\t\t\treturn this->u;\n\t\
    \telse\n\t\t\treturn this->d;\n\t}\n\n\tvoid dbg() {\n\t\tstd::cout << \"{\";\n\
    \t\tstd::cout << \" f: \" << this->f;\n\t\tstd::cout << \" b: \" << this->b;\n\
    \t\tstd::cout << \" u: \" << this->u;\n\t\tstd::cout << \" d: \" << this->d;\n\
    \t\tstd::cout << \" r: \" << this->r;\n\t\tstd::cout << \" l: \" << this->l;\n\
    \t\tstd::cout << \" }\\n\";\n\t}\n};\n"
  code: "#include <cassert>\n#include <iostream>\n#include <vector>\n\nstruct dice\
    \ {\npublic:\n\tint f, u, b, d, r, l;\n\tdice(int f_, int b_, int u_, int d_,\
    \ int r_, int l_)\n\t  : f(f_), b(b_), u(u_), d(d_), r(r_), l(l_) {}\n\tdice()\n\
    \t  : f(3), b(4), u(1), d(6), r(5), l(2) {}\n\n\tvoid rotate(int dir) {\n\t\t\
    assert(0 <= dir and dir < 6);\n\t\tdice ret(*this);\n\t\tswitch(dir) {\n\t\t\t\
    case 0:\n\t\t\t\tret.f = this->u, ret.u = this->b, ret.b = this->d, ret.d = this->f;\n\
    \t\t\t\tbreak;\n\t\t\tcase 1:\n\t\t\t\tret.d = this->r, ret.l = this->d, ret.u\
    \ = this->l, ret.r = this->u;\n\t\t\t\tbreak;\n\t\t\tcase 2:\n\t\t\t\tret.f =\
    \ this->d, ret.u = this->f, ret.b = this->u, ret.d = this->b;\n\t\t\t\tbreak;\n\
    \t\t\tcase 3:\n\t\t\t\tret.d = this->l, ret.l = this->u, ret.u = this->r, ret.r\
    \ = this->d;\n\t\t\t\tbreak;\n\t\t\tcase 4:\n\t\t\t\tret.f = this->l, ret.l =\
    \ this->b, ret.b = this->r, ret.r = this->f;\n\t\t\t\tbreak;\n\t\t\tcase 5:\n\t\
    \t\t\tret.f = this->r, ret.l = this->f, ret.b = this->l, ret.r = this->b;\n\t\t\
    \t\tbreak;\n\t\t\tdefault:\n\t\t\t\tbreak;\n\t\t}\n\t\t*this = ret;\n\t}\n\n\t\
    void rotate_f() { rotate(0); }\n\tvoid rotate_r() { rotate(1); }\n\tvoid rotate_b()\
    \ { rotate(2); }\n\tvoid rotate_l() { rotate(3); }\n\tvoid rotate_ccw() { rotate(4);\
    \ }\n\tvoid rotate_cw() { rotate(5); }\n\n\tstd::vector<dice> make_dice() {\n\t\
    \tstd::vector<dice> ret;\n\t\tfor(int i = 0; i < 6; i++) {\n\t\t\tdice d(*this);\n\
    \t\t\tif(i == 1) d.rotate_f();\n\t\t\tif(i == 2) d.rotate_b();\n\t\t\tif(i ==\
    \ 3) d.rotate_f(), d.rotate_f();\n\t\t\tif(i == 4) d.rotate_ccw();\n\t\t\tif(i\
    \ == 5) d.rotate_cw();\n\t\t\tfor(int j = 0; j < 4; j++) {\n\t\t\t\tret.emplace_back(d);\n\
    \t\t\t\td.rotate_r();\n\t\t\t}\n\t\t}\n\t\treturn ret;\n\t}\n\n\tint operator[](int\
    \ k) {\n\t\tassert(0 <= k and k < 6);\n\t\tif(k == 0)\n\t\t\treturn this->f;\n\
    \t\telse if(k == 1)\n\t\t\treturn this->r;\n\t\telse if(k == 2)\n\t\t\treturn\
    \ this->b;\n\t\telse if(k == 3)\n\t\t\treturn this->l;\n\t\telse if(k == 4)\n\t\
    \t\treturn this->u;\n\t\telse\n\t\t\treturn this->d;\n\t}\n\n\tvoid dbg() {\n\t\
    \tstd::cout << \"{\";\n\t\tstd::cout << \" f: \" << this->f;\n\t\tstd::cout <<\
    \ \" b: \" << this->b;\n\t\tstd::cout << \" u: \" << this->u;\n\t\tstd::cout <<\
    \ \" d: \" << this->d;\n\t\tstd::cout << \" r: \" << this->r;\n\t\tstd::cout <<\
    \ \" l: \" << this->l;\n\t\tstd::cout << \" }\\n\";\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/dice.hpp
  requiredBy: []
  timestamp: '2021-09-07 20:08:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/dice.hpp
layout: document
redirect_from:
- /library/data_structure/dice.hpp
- /library/data_structure/dice.hpp.html
title: data_structure/dice.hpp
---
