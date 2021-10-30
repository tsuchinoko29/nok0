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
    \ -= B[i][k] * a;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn ret;\n\t}\n\n\tmatrix\
    \ inv() {\n\t\tint n = height();\n\t\tif(determinant() == T(0)) return matrix(0);\n\
    \t\tmatrix a(*(this)), l = I(n), u(n);\n\t\tfor(int j = 0; j < n; j++) u[0][j]\
    \ = a[0][j];\n\t\tfor(int j = 1; j < n; j++) l[j][0] = a[j][0] / u[0][0];\n\t\t\
    for(int k = 1; k < n; k++) {\n\t\t\tfor(int j = k; j < n; j++)\n\t\t\t\tfor(int\
    \ i = 0; i < k; i++) a[j][k] -= l[j][i] * u[i][k];\n\t\t\tu[k][k] = a[k][k];\n\
    \t\t\tfor(int j = k + 1; j < n; j++) {\n\t\t\t\tu[k][j] = a[k][j];\n\t\t\t\tfor(int\
    \ i = 0; i < k; i++)\n\t\t\t\t\tu[k][j] -= l[k][i] * u[i][j];\n\t\t\t}\n\t\t\t\
    for(int j = k + 1; j < n; j++) l[j][k] = a[j][k] / u[k][k];\n\t\t}\n\t\tmatrix\
    \ x(n), y = I(n);\n\t\tfor(int i = 0; i < n; i++)\n\t\t\tfor(int j = 0; j < n;\
    \ j++) {\n\t\t\t\tfor(int k = 0; k < j; k++) y[j][i] -= l[j][k] * y[k][i];\n\t\
    \t\t}\n\t\tT sigma;\n\t\tfor(int h = 0; h < n; h++)\n\t\t\tfor(int i = n - 1;\
    \ i >= 0; i--) {\n\t\t\t\tsigma = y[i][h];\n\t\t\t\tfor(int j = i + 1; j < n;\
    \ j++) {\n\t\t\t\t\tsigma -= u[i][j] * x[j][h];\n\t\t\t\t}\n\t\t\t\tx[i][h] =\
    \ sigma / u[i][i];\n\t\t\t}\n\t\treturn move(x);\n\t}\n};\n#line 3 \"math/gauss_jordan.hpp\"\
    \n\ntemplate <class T>\nint gauss_elimination_mint(matrix<T> &mat, bool is_extended\
    \ = false) {\n\tconst int h = mat.height(), w = mat.width();\n\tint rank = 0;\n\
    \tfor(int j = 0; j < w; j++) {\n\t\tif(is_extended and j == w - 1) break;\n\t\t\
    int pivot = -1;\n\t\tfor(int i = rank; i < h; i++) {\n\t\t\tif(mat[i][j] != T(0))\
    \ {\n\t\t\t\tpivot = i;\n\t\t\t\tbreak;\n\t\t\t}\n\t\t}\n\t\tif(pivot == -1) continue;\n\
    \t\tswap(mat[rank], mat[pivot]);\n\n\t\tconst auto cur = T(1) / mat[rank][j];\n\
    \n\t\tfor(int j2 = 0; j2 < w; j2++) mat[rank][j2] *= cur;\n\n\t\tfor(int i = 0;\
    \ i < h; i++) {\n\t\t\tif(i != rank and mat[i][j] != T(0)) {\n\t\t\t\tauto fac\
    \ = mat[i][j];\n\t\t\t\tfor(int j2 = 0; j2 < w; j2++)\n\t\t\t\t\tmat[i][j2] -=\
    \ mat[rank][j2] * fac;\n\t\t\t}\n\t\t}\n\t\trank++;\n\t}\n\treturn rank;\n}\n\n\
    //return {x, rank} s.t. ax = b\n//if no solution, return empty x\ntemplate <class\
    \ T>\nstd::pair<std::vector<T>, int> linear_equation_mint(const matrix<T> &a,\
    \ const std::vector<T> &b) {\n\tint h = a.height(), w = a.width();\n\tmatrix<T>\
    \ eq(h, w + 1);\n\tfor(int i = 0; i < h; i++) {\n\t\tfor(int j = 0; j < w; j++)\
    \ eq[i][j] = a[i][j];\n\t\teq[i][w] = b[i];\n\t}\n\tint rank = gauss_elimination_mint(eq,\
    \ true);\n\n\tfor(int i = rank; i < h; i++)\n\t\tif(eq[i].back() != T(0)) return\
    \ std::pair(vector<T>{}, -1);\n\n\tstd::vector<T> res(h);\n\tfor(int i = 0; i\
    \ < h; i++) res[i] = eq[i].back();\n\n\treturn std::pair(res, rank);\n}\n"
  code: "#pragma once\n#include \"math/matrix.hpp\"\n\ntemplate <class T>\nint gauss_elimination_mint(matrix<T>\
    \ &mat, bool is_extended = false) {\n\tconst int h = mat.height(), w = mat.width();\n\
    \tint rank = 0;\n\tfor(int j = 0; j < w; j++) {\n\t\tif(is_extended and j == w\
    \ - 1) break;\n\t\tint pivot = -1;\n\t\tfor(int i = rank; i < h; i++) {\n\t\t\t\
    if(mat[i][j] != T(0)) {\n\t\t\t\tpivot = i;\n\t\t\t\tbreak;\n\t\t\t}\n\t\t}\n\t\
    \tif(pivot == -1) continue;\n\t\tswap(mat[rank], mat[pivot]);\n\n\t\tconst auto\
    \ cur = T(1) / mat[rank][j];\n\n\t\tfor(int j2 = 0; j2 < w; j2++) mat[rank][j2]\
    \ *= cur;\n\n\t\tfor(int i = 0; i < h; i++) {\n\t\t\tif(i != rank and mat[i][j]\
    \ != T(0)) {\n\t\t\t\tauto fac = mat[i][j];\n\t\t\t\tfor(int j2 = 0; j2 < w; j2++)\n\
    \t\t\t\t\tmat[i][j2] -= mat[rank][j2] * fac;\n\t\t\t}\n\t\t}\n\t\trank++;\n\t\
    }\n\treturn rank;\n}\n\n//return {x, rank} s.t. ax = b\n//if no solution, return\
    \ empty x\ntemplate <class T>\nstd::pair<std::vector<T>, int> linear_equation_mint(const\
    \ matrix<T> &a, const std::vector<T> &b) {\n\tint h = a.height(), w = a.width();\n\
    \tmatrix<T> eq(h, w + 1);\n\tfor(int i = 0; i < h; i++) {\n\t\tfor(int j = 0;\
    \ j < w; j++) eq[i][j] = a[i][j];\n\t\teq[i][w] = b[i];\n\t}\n\tint rank = gauss_elimination_mint(eq,\
    \ true);\n\n\tfor(int i = rank; i < h; i++)\n\t\tif(eq[i].back() != T(0)) return\
    \ std::pair(vector<T>{}, -1);\n\n\tstd::vector<T> res(h);\n\tfor(int i = 0; i\
    \ < h; i++) res[i] = eq[i].back();\n\n\treturn std::pair(res, rank);\n}"
  dependsOn:
  - math/matrix.hpp
  isVerificationFile: false
  path: math/gauss_jordan.hpp
  requiredBy: []
  timestamp: '2021-10-30 20:59:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/gauss_jordan.hpp
layout: document
redirect_from:
- /library/math/gauss_jordan.hpp
- /library/math/gauss_jordan.hpp.html
title: math/gauss_jordan.hpp
---
