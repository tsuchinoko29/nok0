---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo-queue_operate_all_composite.test.cpp
    title: test/yosupo-queue_operate_all_composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/swag.hpp\"\n#include <cassert>\n#include\
    \ <functional>\n#include <stack>\n#include <vector>\n\ntemplate <class S, S (*op)(S,\
    \ S), S (*e)()>\nstruct sliding_window_aggregation {\n\tstatic const size_t inf\
    \ = 1e9;\n\npublic:\n\tsliding_window_aggregation(size_t size = inf) : sz(size),\
    \ front_stack(), back_stack() {}\n\n\tbool empty() const { return front_stack.empty()\
    \ and back_stack.empty(); }\n\n\tsize_t size() const { return front_stack.size()\
    \ + back_stack.size(); }\n\n\tvoid resize(size_t x) { sz = x; }\n\n\tvoid pop()\
    \ {\n\t\tassert(!empty());\n\t\tif(front_stack.empty()) {\n\t\t\tfront_stack.emplace(back_stack.top().val,\
    \ back_stack.top().val);\n\t\t\tback_stack.pop();\n\t\t\twhile(!back_stack.empty())\
    \ {\n\t\t\t\tS tmp = op(back_stack.top().val, front_stack.top().sum);\n\t\t\t\t\
    front_stack.emplace(back_stack.top().val, tmp);\n\t\t\t\tback_stack.pop();\n\t\
    \t\t}\n\t\t}\n\t\tfront_stack.pop();\n\t}\n\n\tS fold_all() {\n\t\tif(sz != inf)\
    \ {\n\t\t\twhile(size() > sz) pop();\n\t\t}\n\t\tif(empty()) return e();\n\t\t\
    if(front_stack.empty())\n\t\t\treturn back_stack.top().sum;\n\t\telse if(back_stack.empty())\n\
    \t\t\treturn front_stack.top().sum;\n\t\telse\n\t\t\treturn op(front_stack.top().sum,\
    \ back_stack.top().sum);\n\t}\n\n\tvoid push(const S x) {\n\t\tif(back_stack.empty())\n\
    \t\t\tback_stack.emplace(x, x);\n\t\telse {\n\t\t\tS s = op(back_stack.top().sum,\
    \ x);\n\t\t\tback_stack.emplace(x, s);\n\t\t}\n\t}\n\nprivate:\n\tstruct node\
    \ {\n\t\tS val, sum;\n\t\tnode(const S &val, const S &sum) : val(val), sum(sum)\
    \ {}\n\t};\n\n\tstd::stack<node> front_stack, back_stack;\n\tsize_t sz;\n};\n"
  code: "#include <cassert>\n#include <functional>\n#include <stack>\n#include <vector>\n\
    \ntemplate <class S, S (*op)(S, S), S (*e)()>\nstruct sliding_window_aggregation\
    \ {\n\tstatic const size_t inf = 1e9;\n\npublic:\n\tsliding_window_aggregation(size_t\
    \ size = inf) : sz(size), front_stack(), back_stack() {}\n\n\tbool empty() const\
    \ { return front_stack.empty() and back_stack.empty(); }\n\n\tsize_t size() const\
    \ { return front_stack.size() + back_stack.size(); }\n\n\tvoid resize(size_t x)\
    \ { sz = x; }\n\n\tvoid pop() {\n\t\tassert(!empty());\n\t\tif(front_stack.empty())\
    \ {\n\t\t\tfront_stack.emplace(back_stack.top().val, back_stack.top().val);\n\t\
    \t\tback_stack.pop();\n\t\t\twhile(!back_stack.empty()) {\n\t\t\t\tS tmp = op(back_stack.top().val,\
    \ front_stack.top().sum);\n\t\t\t\tfront_stack.emplace(back_stack.top().val, tmp);\n\
    \t\t\t\tback_stack.pop();\n\t\t\t}\n\t\t}\n\t\tfront_stack.pop();\n\t}\n\n\tS\
    \ fold_all() {\n\t\tif(sz != inf) {\n\t\t\twhile(size() > sz) pop();\n\t\t}\n\t\
    \tif(empty()) return e();\n\t\tif(front_stack.empty())\n\t\t\treturn back_stack.top().sum;\n\
    \t\telse if(back_stack.empty())\n\t\t\treturn front_stack.top().sum;\n\t\telse\n\
    \t\t\treturn op(front_stack.top().sum, back_stack.top().sum);\n\t}\n\n\tvoid push(const\
    \ S x) {\n\t\tif(back_stack.empty())\n\t\t\tback_stack.emplace(x, x);\n\t\telse\
    \ {\n\t\t\tS s = op(back_stack.top().sum, x);\n\t\t\tback_stack.emplace(x, s);\n\
    \t\t}\n\t}\n\nprivate:\n\tstruct node {\n\t\tS val, sum;\n\t\tnode(const S &val,\
    \ const S &sum) : val(val), sum(sum) {}\n\t};\n\n\tstd::stack<node> front_stack,\
    \ back_stack;\n\tsize_t sz;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/swag.hpp
  requiredBy: []
  timestamp: '2021-09-09 10:43:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo-queue_operate_all_composite.test.cpp
documentation_of: data_structure/swag.hpp
layout: document
redirect_from:
- /library/data_structure/swag.hpp
- /library/data_structure/swag.hpp.html
title: data_structure/swag.hpp
---
