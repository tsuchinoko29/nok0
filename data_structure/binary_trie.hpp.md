---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo-predecessor_problem.test.cpp
    title: test/yosupo-predecessor_problem.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-set_xor_min.test.cpp
    title: test/yosupo-set_xor_min.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/binary_trie.hpp\"\n#include <algorithm>\n\
    #include <cassert>\n#include <iostream>\n#include <memory>\n\ntemplate <class\
    \ T, unsigned char BIT_SIZE = 30, bool multi = true>\nstruct binary_trie {\n\t\
    using u64 = unsigned long long int;\n\npublic:\n\tbinary_trie() : root(new node(0))\
    \ {}\n\n\tu64 count(const T x) { return count(root, x); }\n\n\tvoid insert(const\
    \ T x, const u64 k = 1) {\n\t\tif(multi == false and count(x)) return;\n\t\tinsert(root,\
    \ x, k);\n\t}\n\n\tvoid erase(const T x, const u64 k = 1) {\n\t\tif(!count(x))\
    \ return;\n\t\terase(root, x, k);\n\t}\n\n\tu64 lower_bound(const T x) { return\
    \ lower_bound(root, x); }\n\n\tu64 upper_bound(const T x) { return lower_bound(x\
    \ + 1); }\n\n\tvoid xor_all(const T x) { root->lazy ^= x; }\n\n\tT xor_min(const\
    \ T x) { return xor_min(root, x); }\n\n\tT xor_max(const T x) { return xor_min(x\
    \ ^ MAX) ^ MAX; }\n\n\tT operator[](const u64 k) {\n\t\tassert(0 <= k and k <\
    \ size());\n\t\treturn operator_func(root, k);\n\t}\n\n\tT min_element() { return\
    \ (*this)[0]; }\n\n\tT max_element() { return (*this)[size() - 1]; }\n\n\tu64\
    \ size() const noexcept { return cnt(root); }\n\n\tbool empty() const noexcept\
    \ { return cnt(root) == 0; }\n\n\tvoid dump() {\n\t\tstd::cerr << \"[\";\n\t\t\
    if(!size()) std::cerr << ']';\n\t\tfor(int i = 0; i < size(); i++)\n\t\t\tstd::cerr\
    \ << (*this)[i] << \",]\"[i == size() - 1];\n\t\tstd::cerr << '\\n';\n\t}\n\n\
    private:\n\tstruct node;\n\tusing node_ptr = std::unique_ptr<node>;\n\n\tstruct\
    \ node {\n\t\tT cnt, lazy;\n\t\tnode_ptr descend[2];\n\t\tnode(T cnt) : cnt(cnt),\
    \ lazy(0), descend{nullptr, nullptr} {}\n\t};\n\n\tnode_ptr root;\n\n\tconst T\
    \ MAX = (1ull << BIT_SIZE) - 1;\n\n\tu64 cnt(const node_ptr &t) const { return\
    \ t != nullptr ? t->cnt : 0; }\n\n\tu64 count(node_ptr &t, const T x, const unsigned\
    \ char i = BIT_SIZE - 1) {\n\t\teval(t, i);\n\t\tconst T bit = x >> i & 1;\n\t\
    \tif(t->descend[bit] != nullptr)\n\t\t\treturn (i ? count(t->descend[bit], x,\
    \ i - 1) : cnt(t->descend[bit]));\n\t\telse\n\t\t\treturn 0;\n\t}\n\n\tvoid eval(node_ptr\
    \ &t, const unsigned char i = BIT_SIZE - 1) {\n\t\tif(t->lazy >> i & 1) std::swap(t->descend[0],\
    \ t->descend[1]);\n\t\tif(t->descend[0]) t->descend[0]->lazy ^= t->lazy;\n\t\t\
    if(t->descend[1]) t->descend[1]->lazy ^= t->lazy;\n\t\tt->lazy = 0;\n\t}\n\n\t\
    void insert(node_ptr &t, const T x, const u64 k, const unsigned char i = BIT_SIZE\
    \ - 1) {\n\t\tt->cnt += k;\n\t\teval(t, i);\n\t\tconst T bit = x >> i & 1;\n\t\
    \tif(!t->descend[bit]) t->descend[bit] = std::make_unique<node>(0);\n\t\tif(i)\n\
    \t\t\tinsert(t->descend[bit], x, k, i - 1);\n\t\telse\n\t\t\tt->descend[bit]->cnt\
    \ += k;\n\t}\n\n\tvoid erase(node_ptr &t, const T x, const u64 k, const unsigned\
    \ char i = BIT_SIZE - 1) {\n\t\tt->cnt -= k;\n\t\teval(t, i);\n\t\tconst T bit\
    \ = x >> i & 1;\n\t\tif(i)\n\t\t\terase(t->descend[bit], x, k, i - 1);\n\t\telse\n\
    \t\t\tt->descend[bit]->cnt -= k;\n\t}\n\n\tu64 lower_bound(node_ptr &t, const\
    \ T x, const unsigned char i = BIT_SIZE - 1) {\n\t\tu64 ret = 0;\n\t\teval(t,\
    \ i);\n\t\tif(cnt(t) == 0) return ret;\n\t\tconst T bit = x >> i & 1;\n\t\tif(t->descend[bit])\
    \ {\n\t\t\tif(bit) ret += cnt(t->descend[0]);\n\t\t\treturn ret += (i ? lower_bound(t->descend[bit],\
    \ x, i - 1) : 0);\n\t\t} else\n\t\t\treturn bit ? ret + cnt(t->descend[0]) : ret;\n\
    \t}\n\n\tT xor_min(node_ptr &t, const T x, const unsigned char i = BIT_SIZE -\
    \ 1) {\n\t\teval(t, i);\n\t\tconst T bit = x >> i & 1;\n\t\tif(i == 0)\n\t\t\t\
    return !cnt(t->descend[bit]);\n\t\tif(cnt(t->descend[bit]))\n\t\t\treturn xor_min(t->descend[bit],\
    \ x, i - 1);\n\t\telse {\n\t\t\tif(t->descend[!bit] == nullptr) t->descend[bit]\
    \ = std::make_unique<node>(0);\n\t\t\treturn xor_min(t->descend[!bit], x, i -\
    \ 1) + (1ull << i);\n\t\t}\n\t}\n\n\tT operator_func(node_ptr &t, u64 k, const\
    \ unsigned char i = BIT_SIZE - 1) {\n\t\teval(t, i);\n\t\tif(i == 0) return k\
    \ >= cnt(t->descend[0]);\n\t\tif(k < cnt(t->descend[0]))\n\t\t\treturn operator_func(t->descend[0],\
    \ k, i - 1);\n\t\telse {\n\t\t\tk -= cnt(t->descend[0]);\n\t\t\treturn operator_func(t->descend[1],\
    \ k, i - 1) | (1ULL << i);\n\t\t}\n\t}\n};\n"
  code: "#include <algorithm>\n#include <cassert>\n#include <iostream>\n#include <memory>\n\
    \ntemplate <class T, unsigned char BIT_SIZE = 30, bool multi = true>\nstruct binary_trie\
    \ {\n\tusing u64 = unsigned long long int;\n\npublic:\n\tbinary_trie() : root(new\
    \ node(0)) {}\n\n\tu64 count(const T x) { return count(root, x); }\n\n\tvoid insert(const\
    \ T x, const u64 k = 1) {\n\t\tif(multi == false and count(x)) return;\n\t\tinsert(root,\
    \ x, k);\n\t}\n\n\tvoid erase(const T x, const u64 k = 1) {\n\t\tif(!count(x))\
    \ return;\n\t\terase(root, x, k);\n\t}\n\n\tu64 lower_bound(const T x) { return\
    \ lower_bound(root, x); }\n\n\tu64 upper_bound(const T x) { return lower_bound(x\
    \ + 1); }\n\n\tvoid xor_all(const T x) { root->lazy ^= x; }\n\n\tT xor_min(const\
    \ T x) { return xor_min(root, x); }\n\n\tT xor_max(const T x) { return xor_min(x\
    \ ^ MAX) ^ MAX; }\n\n\tT operator[](const u64 k) {\n\t\tassert(0 <= k and k <\
    \ size());\n\t\treturn operator_func(root, k);\n\t}\n\n\tT min_element() { return\
    \ (*this)[0]; }\n\n\tT max_element() { return (*this)[size() - 1]; }\n\n\tu64\
    \ size() const noexcept { return cnt(root); }\n\n\tbool empty() const noexcept\
    \ { return cnt(root) == 0; }\n\n\tvoid dump() {\n\t\tstd::cerr << \"[\";\n\t\t\
    if(!size()) std::cerr << ']';\n\t\tfor(int i = 0; i < size(); i++)\n\t\t\tstd::cerr\
    \ << (*this)[i] << \",]\"[i == size() - 1];\n\t\tstd::cerr << '\\n';\n\t}\n\n\
    private:\n\tstruct node;\n\tusing node_ptr = std::unique_ptr<node>;\n\n\tstruct\
    \ node {\n\t\tT cnt, lazy;\n\t\tnode_ptr descend[2];\n\t\tnode(T cnt) : cnt(cnt),\
    \ lazy(0), descend{nullptr, nullptr} {}\n\t};\n\n\tnode_ptr root;\n\n\tconst T\
    \ MAX = (1ull << BIT_SIZE) - 1;\n\n\tu64 cnt(const node_ptr &t) const { return\
    \ t != nullptr ? t->cnt : 0; }\n\n\tu64 count(node_ptr &t, const T x, const unsigned\
    \ char i = BIT_SIZE - 1) {\n\t\teval(t, i);\n\t\tconst T bit = x >> i & 1;\n\t\
    \tif(t->descend[bit] != nullptr)\n\t\t\treturn (i ? count(t->descend[bit], x,\
    \ i - 1) : cnt(t->descend[bit]));\n\t\telse\n\t\t\treturn 0;\n\t}\n\n\tvoid eval(node_ptr\
    \ &t, const unsigned char i = BIT_SIZE - 1) {\n\t\tif(t->lazy >> i & 1) std::swap(t->descend[0],\
    \ t->descend[1]);\n\t\tif(t->descend[0]) t->descend[0]->lazy ^= t->lazy;\n\t\t\
    if(t->descend[1]) t->descend[1]->lazy ^= t->lazy;\n\t\tt->lazy = 0;\n\t}\n\n\t\
    void insert(node_ptr &t, const T x, const u64 k, const unsigned char i = BIT_SIZE\
    \ - 1) {\n\t\tt->cnt += k;\n\t\teval(t, i);\n\t\tconst T bit = x >> i & 1;\n\t\
    \tif(!t->descend[bit]) t->descend[bit] = std::make_unique<node>(0);\n\t\tif(i)\n\
    \t\t\tinsert(t->descend[bit], x, k, i - 1);\n\t\telse\n\t\t\tt->descend[bit]->cnt\
    \ += k;\n\t}\n\n\tvoid erase(node_ptr &t, const T x, const u64 k, const unsigned\
    \ char i = BIT_SIZE - 1) {\n\t\tt->cnt -= k;\n\t\teval(t, i);\n\t\tconst T bit\
    \ = x >> i & 1;\n\t\tif(i)\n\t\t\terase(t->descend[bit], x, k, i - 1);\n\t\telse\n\
    \t\t\tt->descend[bit]->cnt -= k;\n\t}\n\n\tu64 lower_bound(node_ptr &t, const\
    \ T x, const unsigned char i = BIT_SIZE - 1) {\n\t\tu64 ret = 0;\n\t\teval(t,\
    \ i);\n\t\tif(cnt(t) == 0) return ret;\n\t\tconst T bit = x >> i & 1;\n\t\tif(t->descend[bit])\
    \ {\n\t\t\tif(bit) ret += cnt(t->descend[0]);\n\t\t\treturn ret += (i ? lower_bound(t->descend[bit],\
    \ x, i - 1) : 0);\n\t\t} else\n\t\t\treturn bit ? ret + cnt(t->descend[0]) : ret;\n\
    \t}\n\n\tT xor_min(node_ptr &t, const T x, const unsigned char i = BIT_SIZE -\
    \ 1) {\n\t\teval(t, i);\n\t\tconst T bit = x >> i & 1;\n\t\tif(i == 0)\n\t\t\t\
    return !cnt(t->descend[bit]);\n\t\tif(cnt(t->descend[bit]))\n\t\t\treturn xor_min(t->descend[bit],\
    \ x, i - 1);\n\t\telse {\n\t\t\tif(t->descend[!bit] == nullptr) t->descend[bit]\
    \ = std::make_unique<node>(0);\n\t\t\treturn xor_min(t->descend[!bit], x, i -\
    \ 1) + (1ull << i);\n\t\t}\n\t}\n\n\tT operator_func(node_ptr &t, u64 k, const\
    \ unsigned char i = BIT_SIZE - 1) {\n\t\teval(t, i);\n\t\tif(i == 0) return k\
    \ >= cnt(t->descend[0]);\n\t\tif(k < cnt(t->descend[0]))\n\t\t\treturn operator_func(t->descend[0],\
    \ k, i - 1);\n\t\telse {\n\t\t\tk -= cnt(t->descend[0]);\n\t\t\treturn operator_func(t->descend[1],\
    \ k, i - 1) | (1ULL << i);\n\t\t}\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/binary_trie.hpp
  requiredBy: []
  timestamp: '2021-09-08 10:12:28+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo-predecessor_problem.test.cpp
  - test/yosupo-set_xor_min.test.cpp
documentation_of: data_structure/binary_trie.hpp
layout: document
redirect_from:
- /library/data_structure/binary_trie.hpp
- /library/data_structure/binary_trie.hpp.html
title: data_structure/binary_trie.hpp
---
