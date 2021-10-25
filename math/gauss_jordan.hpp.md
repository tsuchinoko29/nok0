---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/matrix.hpp
    title: math/matrix.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/matrix.hpp\"\n#include <cassert>\n#include <iostream>\n\
    #include <vector>\n\ntemplate <class T>\nstruct matrix {\nprivate:\n\tstd::vector<std::vector<T>>\
    \ A;\n\n\tstatic matrix I(size_t n) {\n\t\tmatrix mat(n);\n\t\tfor(int i = 0;\
    \ i < n; i++) mat[i][i] = 1;\n\t\treturn mat;\n\t}\n\npublic:\n\tmatrix() = default;\n\
    \n\tmatrix(std::vector<std::vector<T>> &vvec) { A = vvec; }\n\n\tmatrix(size_t\
    \ n, size_t m) : A(n, std::vector<T>(m, 0)) {}\n\n\tmatrix(size_t n, size_t m,\
    \ T init) : A(n, std::vector<T>(m, init)) {}\n\n\tmatrix(size_t n, std::vector<T>\
    \ &vec) : A(n, vec) {}\n\n\tmatrix(size_t n) : A(n, std::vector<T>(n, 0)) {}\n\
    \n\tsize_t height() const { return A.size(); }\n\n\tsize_t width() const { return\
    \ A[0].size(); }\n\n\tinline const std::vector<T> &operator[](int k) const {\n\
    \t\treturn A[k];\n\t}\n\n\tinline std::vector<T> &operator[](int k) {\n\t\treturn\
    \ A[k];\n\t}\n\n\tmatrix &operator+=(const matrix &B) {\n\t\tsize_t n = height(),\
    \ m = width();\n\t\tassert(n == B.height() and m == B.width());\n\t\tfor(int i\
    \ = 0; i < n; i++)\n\t\t\tfor(int j = 0; j < m; j++)\n\t\t\t\t(*this)[i][j] +=\
    \ B[i][j];\n\t\treturn *this;\n\t}\n\n\tmatrix &operator-=(const matrix &B) {\n\
    \t\tsize_t n = height(), m = width();\n\t\tassert(n == B.height() and m == B.width());\n\
    \t\tfor(int i = 0; i < n; i++)\n\t\t\tfor(int j = 0; j < m; j++)\n\t\t\t\t(*this)[i][j]\
    \ -= B[i][j];\n\t\treturn *this;\n\t}\n\n\tmatrix &operator*=(const matrix &B)\
    \ {\n\t\tsize_t n = height(), m = B.width(), p = width();\n\t\tassert(p == B.height());\n\
    \t\tstd::vector<std::vector<T>> C(n, std::vector<T>(m, 0));\n\t\tfor(int i = 0;\
    \ i < n; i++)\n\t\t\tfor(int j = 0; j < m; j++)\n\t\t\t\tfor(int k = 0; k < p;\
    \ k++)\n\t\t\t\t\tC[i][j] += (*this)[i][k] * B[k][j];\n\t\tA.swap(C);\n\t\treturn\
    \ *this;\n\t}\n\n\tmatrix &operator^=(long long k) {\n\t\tmatrix B = matrix::I(height());\n\
    \t\twhile(k > 0) {\n\t\t\tif(k & 1) B *= (*this);\n\t\t\t*this *= *this;\n\t\t\
    \tk >>= 1ll;\n\t\t}\n\t\tA.swap(B.A);\n\t\treturn *this;\n\t}\n\n\tbool operator==(const\
    \ matrix &B) {\n\t\tsize_t n = height(), m = width();\n\t\tif(n != B.height()\
    \ or m != B.width()) return false;\n\t\tfor(int i = 0; i < n; i++)\n\t\t\tfor(int\
    \ j = 0; j < m; j++)\n\t\t\t\tif((*this)[i][j] != B[i][j]) return false;\n\t\t\
    return true;\n\t}\n\n\tmatrix operator+(const matrix &B) const {\n\t\treturn (matrix(*this)\
    \ += B);\n\t}\n\n\tmatrix operator-(const matrix &B) const {\n\t\treturn (matrix(*this)\
    \ -= B);\n\t}\n\n\tmatrix operator*(const matrix &B) const {\n\t\treturn (matrix(*this)\
    \ *= B);\n\t}\n\n\tmatrix operator^(const long long &k) const {\n\t\treturn (matrix(*this)\
    \ ^= k);\n\t}\n\n\tmatrix &operator+=(const T &t) {\n\t\tint n = height(), m =\
    \ width();\n\t\tfor(int i = 0; i < n; i++)\n\t\t\tfor(int j = 0; j < m; j++)\n\
    \t\t\t\t(*this)[i][j] += t;\n\t\treturn *this;\n\t}\n\n\tmatrix &operator-=(const\
    \ T &t) {\n\t\tint n = height(), m = width();\n\t\tfor(int i = 0; i < n; i++)\n\
    \t\t\tfor(int j = 0; j < m; j++)\n\t\t\t\t(*this)[i][j] -= t;\n\t\treturn *this;\n\
    \t}\n\n\tmatrix &operator*=(const T &t) {\n\t\tint n = height(), m = width();\n\
    \t\tfor(int i = 0; i < n; i++)\n\t\t\tfor(int j = 0; j < m; j++)\n\t\t\t\t(*this)[i][j]\
    \ *= t;\n\t\treturn *this;\n\t}\n\n\tmatrix &operator/=(const T &t) {\n\t\tint\
    \ n = height(), m = width();\n\t\tfor(int i = 0; i < n; i++)\n\t\t\tfor(int j\
    \ = 0; j < m; j++)\n\t\t\t\t(*this)[i][j] /= t;\n\t\treturn *this;\n\t}\n\n\t\
    matrix operator+(const T &t) const {\n\t\treturn (matrix(*this) += t);\n\t}\n\n\
    \tmatrix operator-(const T &t) const {\n\t\treturn (matrix(*this) -= t);\n\t}\n\
    \n\tmatrix operator*(const T &t) const {\n\t\treturn (matrix(*this) *= t);\n\t\
    }\n\n\tmatrix operator/(const T &t) const {\n\t\treturn (matrix(*this) /= t);\n\
    \t}\n\n\tfriend std::ostream &operator<<(std::ostream &os, matrix &p) {\n\t\t\
    size_t n = p.height(), m = p.width();\n\t\tfor(int i = 0; i < n; i++) {\n\t\t\t\
    os << '[';\n\t\t\tfor(int j = 0; j < m; j++)\n\t\t\t\tos << p[i][j] << (j == m\
    \ - 1 ? \"]\\n\" : \",\");\n\t\t}\n\t\treturn (os);\n\t}\n\n\tT determinant()\
    \ {\n\t\tmatrix B(*this);\n\t\tsize_t n = height(), m = width();\n\t\tassert(n\
    \ == m);\n\t\tT ret = 1;\n\t\tfor(int i = 0; i < n; i++) {\n\t\t\tint idx = -1;\n\
    \t\t\tfor(int j = i; j < n; j++)\n\t\t\t\tif(B[j][i] != 0) idx = j;\n\t\t\tif(idx\
    \ == -1) return 0;\n\t\t\tif(i != idx) {\n\t\t\t\tret *= -1;\n\t\t\t\tswap(B[i],\
    \ B[idx]);\n\t\t\t}\n\t\t\tret *= B[i][i];\n\t\t\tT vv = B[i][i];\n\t\t\tfor(int\
    \ j = 0; j < n; j++) B[i][j] /= vv;\n\t\t\tfor(int j = i + 1; j < n; j++) {\n\t\
    \t\t\tT a = B[j][i];\n\t\t\t\tfor(int k = 0; k < n; k++) {\n\t\t\t\t\tB[j][k]\
    \ -= B[i][k] * a;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn ret;\n\t}\n};\n#line\
    \ 3 \"math/gauss_jordan.hpp\"\n\ntemplate <class T>\nvoid gauss_elimination(matrix<T>\
    \ &mat) {\n\tconstexpr T eps = 1e-8;\n\tconst int h = mat.height(), w = mat.width();\n\
    \tint rank = 0;\n\tfor(int j = 0; j < w; j++) {\n\t\tint pivot = -1;\n\t\tT mx\
    \ = eps;\n\t\tfor(int i = rank; i < h; i++) {\n\t\t\tif(mx < abs(mat[i][j])) {\n\
    \t\t\t\tmx = abs(mat[i][j]);\n\t\t\t\tpivot = i;\n\t\t\t}\n\t\t}\n\t\tif(pivot\
    \ == -1) continue;\n\t\tswap(mat[rank], mat[pivot]);\n\n\t\tconst auto cur = T(1)\
    \ / mat[rank][j];\n\n\t\tfor(int i = rank + 1; i < n; i++) {\n\t\t\tif(abs(mat[i][j])\
    \ > eps) {\n\t\t\t\tauto tmp = mat[i][j] * cur;\n\t\t\t\tfor(int j2 = i + 1; j2\
    \ < n; j2++)\n\t\t\t\t\tmat[i][j2] -= tmp * mat[rank][j2];\n\t\t\t}\n\t\t}\n\t\
    }\n}\n"
  code: "#pragma once\n#include \"math/matrix.hpp\"\n\ntemplate <class T>\nvoid gauss_elimination(matrix<T>\
    \ &mat) {\n\tconstexpr T eps = 1e-8;\n\tconst int h = mat.height(), w = mat.width();\n\
    \tint rank = 0;\n\tfor(int j = 0; j < w; j++) {\n\t\tint pivot = -1;\n\t\tT mx\
    \ = eps;\n\t\tfor(int i = rank; i < h; i++) {\n\t\t\tif(mx < abs(mat[i][j])) {\n\
    \t\t\t\tmx = abs(mat[i][j]);\n\t\t\t\tpivot = i;\n\t\t\t}\n\t\t}\n\t\tif(pivot\
    \ == -1) continue;\n\t\tswap(mat[rank], mat[pivot]);\n\n\t\tconst auto cur = T(1)\
    \ / mat[rank][j];\n\n\t\tfor(int i = rank + 1; i < n; i++) {\n\t\t\tif(abs(mat[i][j])\
    \ > eps) {\n\t\t\t\tauto tmp = mat[i][j] * cur;\n\t\t\t\tfor(int j2 = i + 1; j2\
    \ < n; j2++)\n\t\t\t\t\tmat[i][j2] -= tmp * mat[rank][j2];\n\t\t\t}\n\t\t}\n\t\
    }\n}"
  dependsOn:
  - math/matrix.hpp
  isVerificationFile: false
  path: math/gauss_jordan.hpp
  requiredBy: []
  timestamp: '2021-10-25 23:54:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/gauss_jordan.hpp
layout: document
redirect_from:
- /library/math/gauss_jordan.hpp
- /library/math/gauss_jordan.hpp.html
title: math/gauss_jordan.hpp
---
