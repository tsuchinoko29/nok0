---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo-predecessor_problem2.test.cpp
    title: test/yosupo-predecessor_problem2.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/w_ary_tree.hpp\"\n#include <array>\n#include\
    \ <cstdint>\n#include <vector>\n\nnamespace w_ary_tree_impl {\nusing u32 = uint32_t;\n\
    using u64 = uint64_t;\nconstexpr u32 ws = 64;\nconstexpr u32 calc_c(u32 n) {\n\
    \tu32 ret = 1;\n\twhile(n > 64) ret *= ws, n /= ws;\n\treturn ret;\n}\nconstexpr\
    \ u32 ceil_div(u32 n, u32 k) {\n\treturn (n + k - 1) / k;\n}\nu32 bsf(const u64\
    \ x) { return __builtin_ctzll(x); }\nu32 bsr(const u64 x) { return 63 - __builtin_clzll(x);\
    \ }\nu64 to_bit(const u32 x) { return static_cast<u64>(1) << x; }\n\ntemplate\
    \ <u32 N, class D = void>\nstruct w_ary_tree {\n\tstatic constexpr u32 C = calc_c(N);\n\
    \tu64 map;\n\tstd::array<w_ary_tree<C>, ceil_div(N, C)> child;\n\npublic:\n\t\
    w_ary_tree() : map(0), child() {}\n\n\tbool insert(const u32 key) {\n\t\tconst\
    \ u32 pos = key / C;\n\t\tmap |= to_bit(pos);\n\t\treturn child[pos].insert(key\
    \ % C);\n\t}\n\n\tbool erase(const u32 key) {\n\t\tconst u32 pos = key / C;\n\t\
    \tconst bool ret = child[pos].erase(key % C);\n\t\tif(child[pos]._get_map() ==\
    \ 0) map ^= to_bit(pos);\n\t\treturn ret;\n\t}\n\n\tbool contains(const u32 key)\
    \ const {\n\t\treturn child[key / C].contains(key % C);\n\t}\n\n\tu32 min() const\
    \ {\n\t\tconst u32 pos = bsf(map);\n\t\treturn pos * C + child[pos].min();\n\t\
    }\n\n\tu32 max() const {\n\t\tconst u32 pos = bsr(map);\n\t\treturn pos * C +\
    \ child[pos].max();\n\t}\n\n\tu32 prev(const u32 key) const {\n\t\tconst u32 pos\
    \ = key / C;\n\t\tconst u32 t = child[pos].prev(key % C);\n\t\tif(t != -1) return\
    \ pos * C + t;\n\t\tconst u64 masked = map & ~(~static_cast<u64>(0) << pos);\n\
    \t\tif(masked) {\n\t\t\tconst u32 pos2 = bsr(masked);\n\t\t\treturn pos2 * C +\
    \ child[pos2].max();\n\t\t} else\n\t\t\treturn -1;\n\t}\n\n\tu32 next(const u32\
    \ key) const {\n\t\tconst u32 pos = key / C;\n\t\tconst u32 t = child[pos].next(key\
    \ % C);\n\t\tif(t != -1) return pos * C + t;\n\t\tconst u64 masked = map & ~(~static_cast<u64>(0)\
    \ >> (63 - pos));\n\t\tif(masked) {\n\t\t\tconst u32 pos2 = bsf(masked);\n\t\t\
    \treturn pos2 * C + child[pos2].min();\n\t\t} else\n\t\t\treturn -1;\n\t}\n\n\t\
    u64 _get_map() const { return map; }\n};\n\ntemplate <u32 N>\nstruct w_ary_tree<N,\
    \ typename std::enable_if<(N <= ws)>::type> {\n\tu64 map;\n\npublic:\n\tw_ary_tree()\
    \ : map(0) {}\n\n\tbool insert(const u32 key) {\n\t\tconst u64 bit = to_bit(key);\n\
    \t\tif(map & bit)\n\t\t\treturn false;\n\t\telse\n\t\t\tmap |= bit;\n\t\treturn\
    \ true;\n\t}\n\n\tbool erase(const u32 key) {\n\t\tconst u64 bit = to_bit(key);\n\
    \t\tif(map & bit) {\n\t\t\tmap ^= bit;\n\t\t\treturn true;\n\t\t}\n\t\treturn\
    \ false;\n\t}\n\n\tbool contains(const u32 key) const {\n\t\treturn map & to_bit(key);\n\
    \t}\n\n\tu32 min() const { return bsf(map); }\n\tu32 max() const { return bsr(map);\
    \ }\n\n\tu32 prev(const u32 key) const {\n\t\tconst u64 masked = map & ~(~static_cast<u64>(0)\
    \ << key);\n\t\tif(masked)\n\t\t\treturn bsr(masked);\n\t\telse\n\t\t\treturn\
    \ -1;\n\t}\n\n\tu32 next(const u32 key) const {\n\t\tconst u64 masked = map &\
    \ (~static_cast<u64>(0) << key);\n\t\tif(masked)\n\t\t\treturn bsf(masked);\n\t\
    \telse\n\t\t\treturn -1;\n\t}\n\n\tu64 _get_map() const { return map; }\n};\n\
    }  // namespace w_ary_tree_impl\n\ntemplate <int N>\nusing w_ary_tree = w_ary_tree_impl::w_ary_tree<static_cast<uint32_t>(N)>;\n"
  code: "#include <array>\n#include <cstdint>\n#include <vector>\n\nnamespace w_ary_tree_impl\
    \ {\nusing u32 = uint32_t;\nusing u64 = uint64_t;\nconstexpr u32 ws = 64;\nconstexpr\
    \ u32 calc_c(u32 n) {\n\tu32 ret = 1;\n\twhile(n > 64) ret *= ws, n /= ws;\n\t\
    return ret;\n}\nconstexpr u32 ceil_div(u32 n, u32 k) {\n\treturn (n + k - 1) /\
    \ k;\n}\nu32 bsf(const u64 x) { return __builtin_ctzll(x); }\nu32 bsr(const u64\
    \ x) { return 63 - __builtin_clzll(x); }\nu64 to_bit(const u32 x) { return static_cast<u64>(1)\
    \ << x; }\n\ntemplate <u32 N, class D = void>\nstruct w_ary_tree {\n\tstatic constexpr\
    \ u32 C = calc_c(N);\n\tu64 map;\n\tstd::array<w_ary_tree<C>, ceil_div(N, C)>\
    \ child;\n\npublic:\n\tw_ary_tree() : map(0), child() {}\n\n\tbool insert(const\
    \ u32 key) {\n\t\tconst u32 pos = key / C;\n\t\tmap |= to_bit(pos);\n\t\treturn\
    \ child[pos].insert(key % C);\n\t}\n\n\tbool erase(const u32 key) {\n\t\tconst\
    \ u32 pos = key / C;\n\t\tconst bool ret = child[pos].erase(key % C);\n\t\tif(child[pos]._get_map()\
    \ == 0) map ^= to_bit(pos);\n\t\treturn ret;\n\t}\n\n\tbool contains(const u32\
    \ key) const {\n\t\treturn child[key / C].contains(key % C);\n\t}\n\n\tu32 min()\
    \ const {\n\t\tconst u32 pos = bsf(map);\n\t\treturn pos * C + child[pos].min();\n\
    \t}\n\n\tu32 max() const {\n\t\tconst u32 pos = bsr(map);\n\t\treturn pos * C\
    \ + child[pos].max();\n\t}\n\n\tu32 prev(const u32 key) const {\n\t\tconst u32\
    \ pos = key / C;\n\t\tconst u32 t = child[pos].prev(key % C);\n\t\tif(t != -1)\
    \ return pos * C + t;\n\t\tconst u64 masked = map & ~(~static_cast<u64>(0) <<\
    \ pos);\n\t\tif(masked) {\n\t\t\tconst u32 pos2 = bsr(masked);\n\t\t\treturn pos2\
    \ * C + child[pos2].max();\n\t\t} else\n\t\t\treturn -1;\n\t}\n\n\tu32 next(const\
    \ u32 key) const {\n\t\tconst u32 pos = key / C;\n\t\tconst u32 t = child[pos].next(key\
    \ % C);\n\t\tif(t != -1) return pos * C + t;\n\t\tconst u64 masked = map & ~(~static_cast<u64>(0)\
    \ >> (63 - pos));\n\t\tif(masked) {\n\t\t\tconst u32 pos2 = bsf(masked);\n\t\t\
    \treturn pos2 * C + child[pos2].min();\n\t\t} else\n\t\t\treturn -1;\n\t}\n\n\t\
    u64 _get_map() const { return map; }\n};\n\ntemplate <u32 N>\nstruct w_ary_tree<N,\
    \ typename std::enable_if<(N <= ws)>::type> {\n\tu64 map;\n\npublic:\n\tw_ary_tree()\
    \ : map(0) {}\n\n\tbool insert(const u32 key) {\n\t\tconst u64 bit = to_bit(key);\n\
    \t\tif(map & bit)\n\t\t\treturn false;\n\t\telse\n\t\t\tmap |= bit;\n\t\treturn\
    \ true;\n\t}\n\n\tbool erase(const u32 key) {\n\t\tconst u64 bit = to_bit(key);\n\
    \t\tif(map & bit) {\n\t\t\tmap ^= bit;\n\t\t\treturn true;\n\t\t}\n\t\treturn\
    \ false;\n\t}\n\n\tbool contains(const u32 key) const {\n\t\treturn map & to_bit(key);\n\
    \t}\n\n\tu32 min() const { return bsf(map); }\n\tu32 max() const { return bsr(map);\
    \ }\n\n\tu32 prev(const u32 key) const {\n\t\tconst u64 masked = map & ~(~static_cast<u64>(0)\
    \ << key);\n\t\tif(masked)\n\t\t\treturn bsr(masked);\n\t\telse\n\t\t\treturn\
    \ -1;\n\t}\n\n\tu32 next(const u32 key) const {\n\t\tconst u64 masked = map &\
    \ (~static_cast<u64>(0) << key);\n\t\tif(masked)\n\t\t\treturn bsf(masked);\n\t\
    \telse\n\t\t\treturn -1;\n\t}\n\n\tu64 _get_map() const { return map; }\n};\n\
    }  // namespace w_ary_tree_impl\n\ntemplate <int N>\nusing w_ary_tree = w_ary_tree_impl::w_ary_tree<static_cast<uint32_t>(N)>;\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/w_ary_tree.hpp
  requiredBy: []
  timestamp: '2021-09-15 13:15:23+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo-predecessor_problem2.test.cpp
documentation_of: data_structure/w_ary_tree.hpp
layout: document
redirect_from:
- /library/data_structure/w_ary_tree.hpp
- /library/data_structure/w_ary_tree.hpp.html
title: data_structure/w_ary_tree.hpp
---
