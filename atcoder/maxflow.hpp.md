---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: atcoder/internal_queue.hpp
    title: atcoder/internal_queue.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: multi.hpp
    title: multi.hpp
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj-2235.test.cpp
    title: test/aoj-2235.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj-2600.test.cpp
    title: test/aoj-2600.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj-2703.test.cpp
    title: test/aoj-2703.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj-alds1_5_d.test.cpp
    title: test/aoj-alds1_5_d.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj-dsl-2-b.test.cpp
    title: test/aoj-dsl-2-b.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj-grl-1-a.test.cpp
    title: test/aoj-grl-1-a.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj-grl-1-b.test.cpp
    title: test/aoj-grl-1-b.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj-grl-1-c.test.cpp
    title: test/aoj-grl-1-c.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj-grl-2-a.test.cpp
    title: test/aoj-grl-2-a.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj-grl-3-a.test.cpp
    title: test/aoj-grl-3-a.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj-grl-3-b.test.cpp
    title: test/aoj-grl-3-b.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj-grl-3-c.test.cpp
    title: test/aoj-grl-3-c.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj-grl-4-a.test.cpp
    title: test/aoj-grl-4-a.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj-grl-4-b.test.cpp
    title: test/aoj-grl-4-b.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj-grl-5-a.test.cpp
    title: test/aoj-grl-5-a.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj-grl-5-b.test.cpp
    title: test/aoj-grl-5-b.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj-grl-5-c.test.cpp
    title: test/aoj-grl-5-c.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj-grl-5-d.test.cpp
    title: test/aoj-grl-5-d.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj-grl-5-e.test.cpp
    title: test/aoj-grl-5-e.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-factorize.test.cpp
    title: test/yosupo-factorize.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-lca.test.cpp
    title: test/yosupo-lca.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-line_add_get_min.test.cpp
    title: test/yosupo-line_add_get_min.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-predecessor_problem.test.cpp
    title: test/yosupo-predecessor_problem.test.cpp
  - icon: ':x:'
    path: test/yosupo-predecessor_problem2.test.cpp
    title: test/yosupo-predecessor_problem2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-scc.test.cpp
    title: test/yosupo-scc.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-segment_add_get_min.test.cpp
    title: test/yosupo-segment_add_get_min.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-set_xor_min.test.cpp
    title: test/yosupo-set_xor_min.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-tree_diameter.test.cpp
    title: test/yosupo-tree_diameter.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-two_edge_connected_components.test.cpp
    title: test/yosupo-two_edge_connected_components.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-vertex_add_path_sum.test.cpp
    title: test/yosupo-vertex_add_path_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-vertex_add_subtree_sum.test.cpp
    title: test/yosupo-vertex_add_subtree_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"atcoder/maxflow.hpp\"\n\n\n\n#include <algorithm>\n#include\
    \ <cassert>\n#include <limits>\n#include <queue>\n#include <vector>\n\n#line 1\
    \ \"atcoder/internal_queue.hpp\"\n\n\n\n#line 5 \"atcoder/internal_queue.hpp\"\
    \n\nnamespace atcoder {\n\nnamespace internal {\n\ntemplate <class T> struct simple_queue\
    \ {\n    std::vector<T> payload;\n    int pos = 0;\n    void reserve(int n) {\
    \ payload.reserve(n); }\n    int size() const { return int(payload.size()) - pos;\
    \ }\n    bool empty() const { return pos == int(payload.size()); }\n    void push(const\
    \ T& t) { payload.push_back(t); }\n    T& front() { return payload[pos]; }\n \
    \   void clear() {\n        payload.clear();\n        pos = 0;\n    }\n    void\
    \ pop() { pos++; }\n};\n\n}  // namespace internal\n\n}  // namespace atcoder\n\
    \n\n#line 11 \"atcoder/maxflow.hpp\"\n\nnamespace atcoder {\n\ntemplate <class\
    \ Cap> struct mf_graph {\n  public:\n    mf_graph() : _n(0) {}\n    explicit mf_graph(int\
    \ n) : _n(n), g(n) {}\n\n    int add_edge(int from, int to, Cap cap) {\n     \
    \   assert(0 <= from && from < _n);\n        assert(0 <= to && to < _n);\n   \
    \     assert(0 <= cap);\n        int m = int(pos.size());\n        pos.push_back({from,\
    \ int(g[from].size())});\n        int from_id = int(g[from].size());\n       \
    \ int to_id = int(g[to].size());\n        if (from == to) to_id++;\n        g[from].push_back(_edge{to,\
    \ to_id, cap});\n        g[to].push_back(_edge{from, from_id, 0});\n        return\
    \ m;\n    }\n\n    struct edge {\n        int from, to;\n        Cap cap, flow;\n\
    \    };\n\n    edge get_edge(int i) {\n        int m = int(pos.size());\n    \
    \    assert(0 <= i && i < m);\n        auto _e = g[pos[i].first][pos[i].second];\n\
    \        auto _re = g[_e.to][_e.rev];\n        return edge{pos[i].first, _e.to,\
    \ _e.cap + _re.cap, _re.cap};\n    }\n    std::vector<edge> edges() {\n      \
    \  int m = int(pos.size());\n        std::vector<edge> result;\n        for (int\
    \ i = 0; i < m; i++) {\n            result.push_back(get_edge(i));\n        }\n\
    \        return result;\n    }\n    void change_edge(int i, Cap new_cap, Cap new_flow)\
    \ {\n        int m = int(pos.size());\n        assert(0 <= i && i < m);\n    \
    \    assert(0 <= new_flow && new_flow <= new_cap);\n        auto& _e = g[pos[i].first][pos[i].second];\n\
    \        auto& _re = g[_e.to][_e.rev];\n        _e.cap = new_cap - new_flow;\n\
    \        _re.cap = new_flow;\n    }\n\n    Cap flow(int s, int t) {\n        return\
    \ flow(s, t, std::numeric_limits<Cap>::max());\n    }\n    Cap flow(int s, int\
    \ t, Cap flow_limit) {\n        assert(0 <= s && s < _n);\n        assert(0 <=\
    \ t && t < _n);\n        assert(s != t);\n\n        std::vector<int> level(_n),\
    \ iter(_n);\n        internal::simple_queue<int> que;\n\n        auto bfs = [&]()\
    \ {\n            std::fill(level.begin(), level.end(), -1);\n            level[s]\
    \ = 0;\n            que.clear();\n            que.push(s);\n            while\
    \ (!que.empty()) {\n                int v = que.front();\n                que.pop();\n\
    \                for (auto e : g[v]) {\n                    if (e.cap == 0 ||\
    \ level[e.to] >= 0) continue;\n                    level[e.to] = level[v] + 1;\n\
    \                    if (e.to == t) return;\n                    que.push(e.to);\n\
    \                }\n            }\n        };\n        auto dfs = [&](auto self,\
    \ int v, Cap up) {\n            if (v == s) return up;\n            Cap res =\
    \ 0;\n            int level_v = level[v];\n            for (int& i = iter[v];\
    \ i < int(g[v].size()); i++) {\n                _edge& e = g[v][i];\n        \
    \        if (level_v <= level[e.to] || g[e.to][e.rev].cap == 0) continue;\n  \
    \              Cap d =\n                    self(self, e.to, std::min(up - res,\
    \ g[e.to][e.rev].cap));\n                if (d <= 0) continue;\n             \
    \   g[v][i].cap += d;\n                g[e.to][e.rev].cap -= d;\n            \
    \    res += d;\n                if (res == up) return res;\n            }\n  \
    \          level[v] = _n;\n            return res;\n        };\n\n        Cap\
    \ flow = 0;\n        while (flow < flow_limit) {\n            bfs();\n       \
    \     if (level[t] == -1) break;\n            std::fill(iter.begin(), iter.end(),\
    \ 0);\n            Cap f = dfs(dfs, t, flow_limit - flow);\n            if (!f)\
    \ break;\n            flow += f;\n        }\n        return flow;\n    }\n\n \
    \   std::vector<bool> min_cut(int s) {\n        std::vector<bool> visited(_n);\n\
    \        internal::simple_queue<int> que;\n        que.push(s);\n        while\
    \ (!que.empty()) {\n            int p = que.front();\n            que.pop();\n\
    \            visited[p] = true;\n            for (auto e : g[p]) {\n         \
    \       if (e.cap && !visited[e.to]) {\n                    visited[e.to] = true;\n\
    \                    que.push(e.to);\n                }\n            }\n     \
    \   }\n        return visited;\n    }\n\n  private:\n    int _n;\n    struct _edge\
    \ {\n        int to, rev;\n        Cap cap;\n    };\n    std::vector<std::pair<int,\
    \ int>> pos;\n    std::vector<std::vector<_edge>> g;\n};\n\n}  // namespace atcoder\n\
    \n\n"
  code: "#ifndef ATCODER_MAXFLOW_HPP\n#define ATCODER_MAXFLOW_HPP 1\n\n#include <algorithm>\n\
    #include <cassert>\n#include <limits>\n#include <queue>\n#include <vector>\n\n\
    #include \"atcoder/internal_queue\"\n\nnamespace atcoder {\n\ntemplate <class\
    \ Cap> struct mf_graph {\n  public:\n    mf_graph() : _n(0) {}\n    explicit mf_graph(int\
    \ n) : _n(n), g(n) {}\n\n    int add_edge(int from, int to, Cap cap) {\n     \
    \   assert(0 <= from && from < _n);\n        assert(0 <= to && to < _n);\n   \
    \     assert(0 <= cap);\n        int m = int(pos.size());\n        pos.push_back({from,\
    \ int(g[from].size())});\n        int from_id = int(g[from].size());\n       \
    \ int to_id = int(g[to].size());\n        if (from == to) to_id++;\n        g[from].push_back(_edge{to,\
    \ to_id, cap});\n        g[to].push_back(_edge{from, from_id, 0});\n        return\
    \ m;\n    }\n\n    struct edge {\n        int from, to;\n        Cap cap, flow;\n\
    \    };\n\n    edge get_edge(int i) {\n        int m = int(pos.size());\n    \
    \    assert(0 <= i && i < m);\n        auto _e = g[pos[i].first][pos[i].second];\n\
    \        auto _re = g[_e.to][_e.rev];\n        return edge{pos[i].first, _e.to,\
    \ _e.cap + _re.cap, _re.cap};\n    }\n    std::vector<edge> edges() {\n      \
    \  int m = int(pos.size());\n        std::vector<edge> result;\n        for (int\
    \ i = 0; i < m; i++) {\n            result.push_back(get_edge(i));\n        }\n\
    \        return result;\n    }\n    void change_edge(int i, Cap new_cap, Cap new_flow)\
    \ {\n        int m = int(pos.size());\n        assert(0 <= i && i < m);\n    \
    \    assert(0 <= new_flow && new_flow <= new_cap);\n        auto& _e = g[pos[i].first][pos[i].second];\n\
    \        auto& _re = g[_e.to][_e.rev];\n        _e.cap = new_cap - new_flow;\n\
    \        _re.cap = new_flow;\n    }\n\n    Cap flow(int s, int t) {\n        return\
    \ flow(s, t, std::numeric_limits<Cap>::max());\n    }\n    Cap flow(int s, int\
    \ t, Cap flow_limit) {\n        assert(0 <= s && s < _n);\n        assert(0 <=\
    \ t && t < _n);\n        assert(s != t);\n\n        std::vector<int> level(_n),\
    \ iter(_n);\n        internal::simple_queue<int> que;\n\n        auto bfs = [&]()\
    \ {\n            std::fill(level.begin(), level.end(), -1);\n            level[s]\
    \ = 0;\n            que.clear();\n            que.push(s);\n            while\
    \ (!que.empty()) {\n                int v = que.front();\n                que.pop();\n\
    \                for (auto e : g[v]) {\n                    if (e.cap == 0 ||\
    \ level[e.to] >= 0) continue;\n                    level[e.to] = level[v] + 1;\n\
    \                    if (e.to == t) return;\n                    que.push(e.to);\n\
    \                }\n            }\n        };\n        auto dfs = [&](auto self,\
    \ int v, Cap up) {\n            if (v == s) return up;\n            Cap res =\
    \ 0;\n            int level_v = level[v];\n            for (int& i = iter[v];\
    \ i < int(g[v].size()); i++) {\n                _edge& e = g[v][i];\n        \
    \        if (level_v <= level[e.to] || g[e.to][e.rev].cap == 0) continue;\n  \
    \              Cap d =\n                    self(self, e.to, std::min(up - res,\
    \ g[e.to][e.rev].cap));\n                if (d <= 0) continue;\n             \
    \   g[v][i].cap += d;\n                g[e.to][e.rev].cap -= d;\n            \
    \    res += d;\n                if (res == up) return res;\n            }\n  \
    \          level[v] = _n;\n            return res;\n        };\n\n        Cap\
    \ flow = 0;\n        while (flow < flow_limit) {\n            bfs();\n       \
    \     if (level[t] == -1) break;\n            std::fill(iter.begin(), iter.end(),\
    \ 0);\n            Cap f = dfs(dfs, t, flow_limit - flow);\n            if (!f)\
    \ break;\n            flow += f;\n        }\n        return flow;\n    }\n\n \
    \   std::vector<bool> min_cut(int s) {\n        std::vector<bool> visited(_n);\n\
    \        internal::simple_queue<int> que;\n        que.push(s);\n        while\
    \ (!que.empty()) {\n            int p = que.front();\n            que.pop();\n\
    \            visited[p] = true;\n            for (auto e : g[p]) {\n         \
    \       if (e.cap && !visited[e.to]) {\n                    visited[e.to] = true;\n\
    \                    que.push(e.to);\n                }\n            }\n     \
    \   }\n        return visited;\n    }\n\n  private:\n    int _n;\n    struct _edge\
    \ {\n        int to, rev;\n        Cap cap;\n    };\n    std::vector<std::pair<int,\
    \ int>> pos;\n    std::vector<std::vector<_edge>> g;\n};\n\n}  // namespace atcoder\n\
    \n#endif  // ATCODER_MAXFLOW_HPP\n"
  dependsOn:
  - atcoder/internal_queue.hpp
  isVerificationFile: false
  path: atcoder/maxflow.hpp
  requiredBy:
  - multi.hpp
  - template.hpp
  timestamp: '2021-09-08 15:21:46+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo-two_edge_connected_components.test.cpp
  - test/aoj-grl-3-b.test.cpp
  - test/yosupo-predecessor_problem.test.cpp
  - test/yosupo-segment_add_get_min.test.cpp
  - test/aoj-grl-4-b.test.cpp
  - test/yosupo-line_add_get_min.test.cpp
  - test/aoj-grl-4-a.test.cpp
  - test/yosupo-tree_diameter.test.cpp
  - test/aoj-grl-1-a.test.cpp
  - test/yosupo-lca.test.cpp
  - test/yosupo-predecessor_problem2.test.cpp
  - test/aoj-grl-3-c.test.cpp
  - test/aoj-grl-5-e.test.cpp
  - test/aoj-2703.test.cpp
  - test/aoj-grl-5-a.test.cpp
  - test/aoj-grl-5-c.test.cpp
  - test/yosupo-set_xor_min.test.cpp
  - test/aoj-grl-1-b.test.cpp
  - test/yosupo-vertex_add_path_sum.test.cpp
  - test/aoj-dsl-2-b.test.cpp
  - test/aoj-2235.test.cpp
  - test/aoj-grl-3-a.test.cpp
  - test/aoj-grl-1-c.test.cpp
  - test/aoj-alds1_5_d.test.cpp
  - test/aoj-grl-5-d.test.cpp
  - test/aoj-grl-5-b.test.cpp
  - test/yosupo-vertex_add_subtree_sum.test.cpp
  - test/aoj-2600.test.cpp
  - test/aoj-grl-2-a.test.cpp
  - test/yosupo-factorize.test.cpp
  - test/yosupo-scc.test.cpp
documentation_of: atcoder/maxflow.hpp
layout: document
redirect_from:
- /library/atcoder/maxflow.hpp
- /library/atcoder/maxflow.hpp.html
title: atcoder/maxflow.hpp
---
