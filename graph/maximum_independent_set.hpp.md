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
  bundledCode: "#line 2 \"graph/maximum_independent_set.hpp\"\n#include <vector>\n\
    \ntemplate <class T>\nT maximum_independent_set(std::vector<std::vector<int>>\
    \ graph, std::vector<T> weight) {\n\tconst int n = graph.size();\n\tassert(n ==\
    \ (int)weight.size());\n\tconst int l = n / 2, r = n - l;\n\tconst int right_rev_mask\
    \ = (1 << r) - 1;\n\tstd::vector lef_mask(l, 0), rig_mask(r, 0), lef_rig_mask(l,\
    \ 0);\n\tfor(int i = 0; i < l; i++) {\n\t\tfor(int j = 0; j < l; j++) lef_mask[i]\
    \ |= graph[i][j] << j;\n\t\tfor(int j = 0; j < r; j++) lef_rig_mask[i] |= graph[i][l\
    \ + j] << j;\n\t}\n\tfor(int i = 0; i < r; i++) {\n\t\tfor(int j = 0; j < r; j++)\
    \ rig_mask[i] |= graph[l + i][l + j] << j;\n\t}\n\n\tstd::vector<T> right_solve(1\
    \ << r);\n\tfor(int bit = 0; bit < 1 << r; bit++) {\n\t\tint rmask = 0;\n\t\t\
    T sum = 0;\n\t\tfor(int i = 0; i < r; i++) {\n\t\t\tif(bit >> i & 1) rmask |=\
    \ rig_mask[i], sum += weight[l + i];\n\t\t}\n\t\tif(rmask & bit) continue;\n\t\
    \tright_solve[bit] = sum;\n\t}\n\tfor(int i = 0; i < r; i++) {\n\t\tfor(int bit\
    \ = 0; bit < 1 << r; bit++) {\n\t\t\tif(bit & (1 << i)) right_solve[bit] = max(right_solve[bit],\
    \ right_solve[bit ^ (1 << i)]);\n\t\t}\n\t}\n\n\tT res = 0;\n\n\tfor(int bit =\
    \ 0; bit < 1 << l; bit++) {\n\t\tT sum = 0;\n\t\tint lmask = 0, rmask = 0;\n\t\
    \tfor(int i = 0; i < l; i++) {\n\t\t\tif(bit >> i & 1) {\n\t\t\t\tlmask |= lef_mask[i];\n\
    \t\t\t\trmask |= lef_rig_mask[i];\n\t\t\t\tsum += weight[i];\n\t\t\t}\n\t\t}\n\
    \t\tif(lmask & bit) continue;\n\t\tres = max(res, sum + right_solve[rmask ^ right_rev_mask]);\n\
    \t}\n\treturn res;\n}\n\nint maximum_independent_set(std::vector<std::vector<int>>\
    \ graph) {\n\tconst int n = (int)graph.size();\n\treturn maximum_independent_set(graph,\
    \ std::vector(n, 1));\n}\n"
  code: "#pragma once\n#include <vector>\n\ntemplate <class T>\nT maximum_independent_set(std::vector<std::vector<int>>\
    \ graph, std::vector<T> weight) {\n\tconst int n = graph.size();\n\tassert(n ==\
    \ (int)weight.size());\n\tconst int l = n / 2, r = n - l;\n\tconst int right_rev_mask\
    \ = (1 << r) - 1;\n\tstd::vector lef_mask(l, 0), rig_mask(r, 0), lef_rig_mask(l,\
    \ 0);\n\tfor(int i = 0; i < l; i++) {\n\t\tfor(int j = 0; j < l; j++) lef_mask[i]\
    \ |= graph[i][j] << j;\n\t\tfor(int j = 0; j < r; j++) lef_rig_mask[i] |= graph[i][l\
    \ + j] << j;\n\t}\n\tfor(int i = 0; i < r; i++) {\n\t\tfor(int j = 0; j < r; j++)\
    \ rig_mask[i] |= graph[l + i][l + j] << j;\n\t}\n\n\tstd::vector<T> right_solve(1\
    \ << r);\n\tfor(int bit = 0; bit < 1 << r; bit++) {\n\t\tint rmask = 0;\n\t\t\
    T sum = 0;\n\t\tfor(int i = 0; i < r; i++) {\n\t\t\tif(bit >> i & 1) rmask |=\
    \ rig_mask[i], sum += weight[l + i];\n\t\t}\n\t\tif(rmask & bit) continue;\n\t\
    \tright_solve[bit] = sum;\n\t}\n\tfor(int i = 0; i < r; i++) {\n\t\tfor(int bit\
    \ = 0; bit < 1 << r; bit++) {\n\t\t\tif(bit & (1 << i)) right_solve[bit] = max(right_solve[bit],\
    \ right_solve[bit ^ (1 << i)]);\n\t\t}\n\t}\n\n\tT res = 0;\n\n\tfor(int bit =\
    \ 0; bit < 1 << l; bit++) {\n\t\tT sum = 0;\n\t\tint lmask = 0, rmask = 0;\n\t\
    \tfor(int i = 0; i < l; i++) {\n\t\t\tif(bit >> i & 1) {\n\t\t\t\tlmask |= lef_mask[i];\n\
    \t\t\t\trmask |= lef_rig_mask[i];\n\t\t\t\tsum += weight[i];\n\t\t\t}\n\t\t}\n\
    \t\tif(lmask & bit) continue;\n\t\tres = max(res, sum + right_solve[rmask ^ right_rev_mask]);\n\
    \t}\n\treturn res;\n}\n\nint maximum_independent_set(std::vector<std::vector<int>>\
    \ graph) {\n\tconst int n = (int)graph.size();\n\treturn maximum_independent_set(graph,\
    \ std::vector(n, 1));\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/maximum_independent_set.hpp
  requiredBy: []
  timestamp: '2021-10-30 20:59:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/maximum_independent_set.hpp
layout: document
redirect_from:
- /library/graph/maximum_independent_set.hpp
- /library/graph/maximum_independent_set.hpp.html
title: graph/maximum_independent_set.hpp
---
