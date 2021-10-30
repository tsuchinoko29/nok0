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
  bundledCode: "#line 2 \"data_structure/rolling_hash.hpp\"\n#include <cassert>\n\
    #include <vector>\n\ntemplate <typename T>\nstruct rolling_hash {\nprivate:\n\t\
    int n;\n\tconst long long mod = (1ll << 61) - 1;\n\tconst int base = 1007;\n\t\
    std::vector<__int128_t> hash, power;\n\npublic:\n\trolling_hash() = default;\n\
    \n\trolling_hash(const T &s) : n(s.size()) {\n\t\thash.assign(n + 1, 0);\n\t\t\
    power.assign(n + 1, 1);\n\t\tfor(int i = 0; i < n; i++) {\n\t\t\thash[i + 1] =\
    \ (hash[i] * base + s[i]) % mod;\n\t\t\tpower[i + 1] = (power[i] * base) % mod;\n\
    \t\t}\n\t}\n\t//[l, r)\u306Ehash\u5024\u3092\u53D6\u5F97\n\tlong long get(const\
    \ int l, const int r) const {\n\t\tassert(l < r and l >= 0 and r <= n);\n\t\t\
    long long res = hash[r] - hash[l] * power[r - l] % mod;\n\t\tif(res < 0) res +=\
    \ mod;\n\t\treturn res;\n\t}\n\n\t//\u5168\u4F53\u306Ehash\u3092\u53D6\u5F97\n\
    \tlong long s_hash() const { return get(0, n); }\n\n\t//[a, n) \u3068[b, n)\u306E\
    \u6700\u9577\u5171\u901A\u63A5\u982D\u8F9E\u306E\u9577\u3055\u3092\u53D6\u5F97\
    \n\tint getLCP(const int a, const int b) const {\n\t\tassert(a >= 0 and a < n\
    \ and b >= 0 and b < n);\n\t\tint len = std::min(n - a, n - b), ok = 0, ng = len;\n\
    \t\twhile(ng - ok > 1) {\n\t\t\tint mid = (ok + ng) / 2;\n\t\t\tif(get(a, a +\
    \ mid) != get(b, b + mid))\n\t\t\t\tng = mid;\n\t\t\telse\n\t\t\t\tok = mid;\n\
    \t\t}\n\t\treturn ok;\n\t}\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\n\ntemplate <typename\
    \ T>\nstruct rolling_hash {\nprivate:\n\tint n;\n\tconst long long mod = (1ll\
    \ << 61) - 1;\n\tconst int base = 1007;\n\tstd::vector<__int128_t> hash, power;\n\
    \npublic:\n\trolling_hash() = default;\n\n\trolling_hash(const T &s) : n(s.size())\
    \ {\n\t\thash.assign(n + 1, 0);\n\t\tpower.assign(n + 1, 1);\n\t\tfor(int i =\
    \ 0; i < n; i++) {\n\t\t\thash[i + 1] = (hash[i] * base + s[i]) % mod;\n\t\t\t\
    power[i + 1] = (power[i] * base) % mod;\n\t\t}\n\t}\n\t//[l, r)\u306Ehash\u5024\
    \u3092\u53D6\u5F97\n\tlong long get(const int l, const int r) const {\n\t\tassert(l\
    \ < r and l >= 0 and r <= n);\n\t\tlong long res = hash[r] - hash[l] * power[r\
    \ - l] % mod;\n\t\tif(res < 0) res += mod;\n\t\treturn res;\n\t}\n\n\t//\u5168\
    \u4F53\u306Ehash\u3092\u53D6\u5F97\n\tlong long s_hash() const { return get(0,\
    \ n); }\n\n\t//[a, n) \u3068[b, n)\u306E\u6700\u9577\u5171\u901A\u63A5\u982D\u8F9E\
    \u306E\u9577\u3055\u3092\u53D6\u5F97\n\tint getLCP(const int a, const int b) const\
    \ {\n\t\tassert(a >= 0 and a < n and b >= 0 and b < n);\n\t\tint len = std::min(n\
    \ - a, n - b), ok = 0, ng = len;\n\t\twhile(ng - ok > 1) {\n\t\t\tint mid = (ok\
    \ + ng) / 2;\n\t\t\tif(get(a, a + mid) != get(b, b + mid))\n\t\t\t\tng = mid;\n\
    \t\t\telse\n\t\t\t\tok = mid;\n\t\t}\n\t\treturn ok;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/rolling_hash.hpp
  requiredBy: []
  timestamp: '2021-10-30 20:59:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/rolling_hash.hpp
layout: document
redirect_from:
- /library/data_structure/rolling_hash.hpp
- /library/data_structure/rolling_hash.hpp.html
title: data_structure/rolling_hash.hpp
---
