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
  bundledCode: "#line 1 \"random/xorshift.hpp\"\n#include <stdint.h>\n\nstruct xorshift\
    \ {\n\tusing u32 = uint32_t;\n\tu32 x = 123456789, y = 362436069, z = 521288629,\
    \ w = 88675123;\n\txorshift(u32 seed = 0) { z ^= seed; }\n\tu32 operator()() {\n\
    \t\tu32 t = x ^ (x << 11);\n\t\tx = y;\n\t\ty = z;\n\t\tz = w;\n\t\treturn w =\
    \ (w ^ (w >> 19)) ^ (t ^ (t >> 8));\n\t}\n};\n"
  code: "#include <stdint.h>\n\nstruct xorshift {\n\tusing u32 = uint32_t;\n\tu32\
    \ x = 123456789, y = 362436069, z = 521288629, w = 88675123;\n\txorshift(u32 seed\
    \ = 0) { z ^= seed; }\n\tu32 operator()() {\n\t\tu32 t = x ^ (x << 11);\n\t\t\
    x = y;\n\t\ty = z;\n\t\tz = w;\n\t\treturn w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));\n\
    \t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: random/xorshift.hpp
  requiredBy: []
  timestamp: '2021-09-07 20:08:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: random/xorshift.hpp
layout: document
redirect_from:
- /library/random/xorshift.hpp
- /library/random/xorshift.hpp.html
title: random/xorshift.hpp
---
