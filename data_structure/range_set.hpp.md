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
  bundledCode: "#line 1 \"data_structure/range_set.hpp\"\n#include <cassert>\n#include\
    \ <iostream>\n#include <limits>\n#include <set>\n#include <vector>\n\ntemplate\
    \ <class T>\nstruct range_set {\nprivate:\n\tconst T TINF = std::numeric_limits<T>::max()\
    \ / 2;\n\tT sum;\n\tstd::set<std::pair<T, T>> st;\n\npublic:\n\trange_set() :\
    \ sum(0) {\n\t\tst.emplace(-TINF, -TINF);\n\t\tst.emplace(TINF, TINF);\n\t}\n\n\
    \t//[l, r) is covered?\n\tbool covered(const T l, const T r) {\n\t\tassert(l <=\
    \ r);\n\t\tif(l == r) return true;\n\t\tauto itr = prev(st.upper_bound({l, TINF}));\n\
    \t\treturn itr->first <= l and r <= itr->second;\n\t}\n\n\t//[x, x + 1) is covered?\n\
    \tbool covered(const T x) { return covered(x, x + 1); }\n\n\t//return section\
    \ which covers[l, r)\n\t//if not exists, return[-TINF, -TINF)\n\tstd::pair<T,\
    \ T> covered_by(const T l, const T r) {\n\t\tassert(l <= r);\n\t\tif(l == r) return\
    \ {-TINF, -TINF};\n\t\tauto itr = prev(st.upper_bound({l, TINF}));\n\t\tif(itr->first\
    \ <= l and r <= itr->second) return *itr;\n\t\treturn {-TINF, -TINF};\n\t}\n\n\
    \t//return section which covers[x, x + 1)\n\t//if not exists, return[-TINF, -TINF)\n\
    \tstd::pair<T, T> covered_by(const T x) { return covered_by(x, x + 1); }\n\n\t\
    //insert[l, r), and return increment\n\tT insert(T l, T r) {\n\t\tassert(l <=\
    \ r);\n\t\tif(l == r) return T(0);\n\t\tauto itr = prev(st.upper_bound({l, TINF}));\n\
    \t\tif(itr->first <= l and r <= itr->second) return T(0);\n\t\tT sum_erased =\
    \ T(0);\n\t\tif(itr->first <= l and l <= itr->second) {\n\t\t\tl = itr->first;\n\
    \t\t\tsum_erased += itr->second - itr->first;\n\t\t\titr = st.erase(itr);\n\t\t\
    } else\n\t\t\titr = next(itr);\n\t\twhile(r > itr->second) {\n\t\t\tsum_erased\
    \ += itr->second - itr->first;\n\t\t\titr = st.erase(itr);\n\t\t}\n\t\tif(itr->first\
    \ <= r) {\n\t\t\tsum_erased += itr->second - itr->first;\n\t\t\tr = itr->second;\n\
    \t\t\tst.erase(itr);\n\t\t}\n\t\tst.emplace(l, r);\n\t\tsum += r - l - sum_erased;\n\
    \t\treturn r - l - sum_erased;\n\t}\n\n\t//insert[x, x + 1), and return increment\n\
    \tT insert(const T x) { return insert(x, x + 1); }\n\n\t// erase [l, r), and return\
    \ decrement\n\tT erase(const T l, const T r) {\n\t\tassert(l <= r);\n\t\tif(l\
    \ == r) return T(0);\n\t\tauto itr = prev(st.upper_bound({l, TINF}));\n\t\tif(itr->first\
    \ <= l and r <= itr->second) {\n\t\t\tif(itr->first < l) st.emplace(itr->first,\
    \ l);\n\t\t\tif(r < itr->second) st.emplace(r, itr->second);\n\t\t\tst.erase(itr);\n\
    \t\t\tsum -= r - l;\n\t\t\treturn r - l;\n\t\t}\n\n\t\tT ret = T(0);\n\t\tif(itr->first\
    \ <= l and l < itr->second) {\n\t\t\tret += itr->second - l;\n\t\t\tif(itr->first\
    \ < l) st.emplace(itr->first, l);\n\t\t\titr = st.erase(itr);\n\t\t} else\n\t\t\
    \titr = next(itr);\n\t\twhile(itr->second <= r) {\n\t\t\tret += itr->second -\
    \ itr->first;\n\t\t\titr = st.erase(itr);\n\t\t}\n\t\tif(itr->first < r) {\n\t\
    \t\tret += r - itr->first;\n\t\t\tst.emplace(r, itr->second);\n\t\t\tst.erase(itr);\n\
    \t\t}\n\t\tsum -= ret;\n\t\treturn ret;\n\t}\n\n\t// erase [x, x + 1), and return\
    \ decrement\n\tT erase(const T x) { return erase(x, x + 1); }\n\n\tint size()\
    \ const { return (int)st.size() - 2; }\n\n\tT mex(const T x = 0) const {\n\t\t\
    auto itr = prev(st.upper_bound({x, TINF}));\n\t\tif(itr->first <= x and x < itr->second)\n\
    \t\t\treturn itr->second;\n\t\telse\n\t\t\treturn x;\n\t}\n\n\tT sum_all() const\
    \ { return sum; }\n\n\tstd::set<std::pair<T, T>> get() const {\n\t\tstd::set<std::pair<T,\
    \ T>> res;\n\t\tfor(auto &p : st) {\n\t\t\tif(std::abs(p.first) == TINF) continue;\n\
    \t\t\tres.emplace(p.first, p.second);\n\t\t}\n\t\treturn res;\n\t}\n\n\tvoid dump()\
    \ const {\n\t\tstd::cout << \"range_set:\";\n\t\tfor(auto &p : st) {\n\t\t\tif(std::abs(p.first)\
    \ == TINF) continue;\n\t\t\tstd::cout << \"[\" << p.first << \",\" << p.second\
    \ << \"),\";\n\t\t}\n\t\tstd::cout << '\\n';\n\t}\n};\n"
  code: "#include <cassert>\n#include <iostream>\n#include <limits>\n#include <set>\n\
    #include <vector>\n\ntemplate <class T>\nstruct range_set {\nprivate:\n\tconst\
    \ T TINF = std::numeric_limits<T>::max() / 2;\n\tT sum;\n\tstd::set<std::pair<T,\
    \ T>> st;\n\npublic:\n\trange_set() : sum(0) {\n\t\tst.emplace(-TINF, -TINF);\n\
    \t\tst.emplace(TINF, TINF);\n\t}\n\n\t//[l, r) is covered?\n\tbool covered(const\
    \ T l, const T r) {\n\t\tassert(l <= r);\n\t\tif(l == r) return true;\n\t\tauto\
    \ itr = prev(st.upper_bound({l, TINF}));\n\t\treturn itr->first <= l and r <=\
    \ itr->second;\n\t}\n\n\t//[x, x + 1) is covered?\n\tbool covered(const T x) {\
    \ return covered(x, x + 1); }\n\n\t//return section which covers[l, r)\n\t//if\
    \ not exists, return[-TINF, -TINF)\n\tstd::pair<T, T> covered_by(const T l, const\
    \ T r) {\n\t\tassert(l <= r);\n\t\tif(l == r) return {-TINF, -TINF};\n\t\tauto\
    \ itr = prev(st.upper_bound({l, TINF}));\n\t\tif(itr->first <= l and r <= itr->second)\
    \ return *itr;\n\t\treturn {-TINF, -TINF};\n\t}\n\n\t//return section which covers[x,\
    \ x + 1)\n\t//if not exists, return[-TINF, -TINF)\n\tstd::pair<T, T> covered_by(const\
    \ T x) { return covered_by(x, x + 1); }\n\n\t//insert[l, r), and return increment\n\
    \tT insert(T l, T r) {\n\t\tassert(l <= r);\n\t\tif(l == r) return T(0);\n\t\t\
    auto itr = prev(st.upper_bound({l, TINF}));\n\t\tif(itr->first <= l and r <= itr->second)\
    \ return T(0);\n\t\tT sum_erased = T(0);\n\t\tif(itr->first <= l and l <= itr->second)\
    \ {\n\t\t\tl = itr->first;\n\t\t\tsum_erased += itr->second - itr->first;\n\t\t\
    \titr = st.erase(itr);\n\t\t} else\n\t\t\titr = next(itr);\n\t\twhile(r > itr->second)\
    \ {\n\t\t\tsum_erased += itr->second - itr->first;\n\t\t\titr = st.erase(itr);\n\
    \t\t}\n\t\tif(itr->first <= r) {\n\t\t\tsum_erased += itr->second - itr->first;\n\
    \t\t\tr = itr->second;\n\t\t\tst.erase(itr);\n\t\t}\n\t\tst.emplace(l, r);\n\t\
    \tsum += r - l - sum_erased;\n\t\treturn r - l - sum_erased;\n\t}\n\n\t//insert[x,\
    \ x + 1), and return increment\n\tT insert(const T x) { return insert(x, x + 1);\
    \ }\n\n\t// erase [l, r), and return decrement\n\tT erase(const T l, const T r)\
    \ {\n\t\tassert(l <= r);\n\t\tif(l == r) return T(0);\n\t\tauto itr = prev(st.upper_bound({l,\
    \ TINF}));\n\t\tif(itr->first <= l and r <= itr->second) {\n\t\t\tif(itr->first\
    \ < l) st.emplace(itr->first, l);\n\t\t\tif(r < itr->second) st.emplace(r, itr->second);\n\
    \t\t\tst.erase(itr);\n\t\t\tsum -= r - l;\n\t\t\treturn r - l;\n\t\t}\n\n\t\t\
    T ret = T(0);\n\t\tif(itr->first <= l and l < itr->second) {\n\t\t\tret += itr->second\
    \ - l;\n\t\t\tif(itr->first < l) st.emplace(itr->first, l);\n\t\t\titr = st.erase(itr);\n\
    \t\t} else\n\t\t\titr = next(itr);\n\t\twhile(itr->second <= r) {\n\t\t\tret +=\
    \ itr->second - itr->first;\n\t\t\titr = st.erase(itr);\n\t\t}\n\t\tif(itr->first\
    \ < r) {\n\t\t\tret += r - itr->first;\n\t\t\tst.emplace(r, itr->second);\n\t\t\
    \tst.erase(itr);\n\t\t}\n\t\tsum -= ret;\n\t\treturn ret;\n\t}\n\n\t// erase [x,\
    \ x + 1), and return decrement\n\tT erase(const T x) { return erase(x, x + 1);\
    \ }\n\n\tint size() const { return (int)st.size() - 2; }\n\n\tT mex(const T x\
    \ = 0) const {\n\t\tauto itr = prev(st.upper_bound({x, TINF}));\n\t\tif(itr->first\
    \ <= x and x < itr->second)\n\t\t\treturn itr->second;\n\t\telse\n\t\t\treturn\
    \ x;\n\t}\n\n\tT sum_all() const { return sum; }\n\n\tstd::set<std::pair<T, T>>\
    \ get() const {\n\t\tstd::set<std::pair<T, T>> res;\n\t\tfor(auto &p : st) {\n\
    \t\t\tif(std::abs(p.first) == TINF) continue;\n\t\t\tres.emplace(p.first, p.second);\n\
    \t\t}\n\t\treturn res;\n\t}\n\n\tvoid dump() const {\n\t\tstd::cout << \"range_set:\"\
    ;\n\t\tfor(auto &p : st) {\n\t\t\tif(std::abs(p.first) == TINF) continue;\n\t\t\
    \tstd::cout << \"[\" << p.first << \",\" << p.second << \"),\";\n\t\t}\n\t\tstd::cout\
    \ << '\\n';\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/range_set.hpp
  requiredBy: []
  timestamp: '2021-09-07 20:08:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/range_set.hpp
layout: document
redirect_from:
- /library/data_structure/range_set.hpp
- /library/data_structure/range_set.hpp.html
title: data_structure/range_set.hpp
---
