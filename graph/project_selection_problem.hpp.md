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
  bundledCode: "#line 2 \"graph/project_selection_problem.hpp\"\n\n#include <algorithm>\n\
    #include <cassert>\n#include <iostream>\n#include <limits>\n#include <queue>\n\
    #include <vector>\n\nnamespace project_selection_problem_impl {\n\ntemplate <typename\
    \ flow_t>\nstruct dinic {\nprivate:\n\tconst flow_t INF;\n\tstruct edge {\n\t\t\
    int to;\n\t\tflow_t cap;\n\t\tint rev;\n\t\tbool isrev;\n\t\tint idx;\n\t};\n\t\
    std::vector<std::vector<edge>> graph;\n\tstd::vector<int> min_cost, iter;\n\n\t\
    bool bfs(int s, int t) {\n\t\tmin_cost.assign(graph.size(), -1);\n\t\tstd::queue<int>\
    \ que;\n\t\tmin_cost[s] = 0;\n\t\tque.push(s);\n\t\twhile(!que.empty() and min_cost[t]\
    \ == -1) {\n\t\t\tint p = que.front();\n\t\t\tque.pop();\n\t\t\tfor(auto &e :\
    \ graph[p]) {\n\t\t\t\tif(e.cap > 0 and min_cost[e.to] == -1) {\n\t\t\t\t\tmin_cost[e.to]\
    \ = min_cost[p] + 1;\n\t\t\t\t\tque.push(e.to);\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\
    \treturn min_cost[t] != -1;\n\t}\n\n\tflow_t dfs(int idx, const int t, flow_t\
    \ flow) {\n\t\tif(idx == t) return flow;\n\t\tfor(int &i = iter[idx]; i < SZ(graph[idx]);\
    \ i++) {\n\t\t\tedge &e = graph[idx][i];\n\t\t\tif(e.cap > 0 and min_cost[idx]\
    \ < min_cost[e.to]) {\n\t\t\t\tflow_t d = dfs(e.to, t, min(flow, e.cap));\n\t\t\
    \t\tif(d > 0) {\n\t\t\t\t\te.cap -= d;\n\t\t\t\t\tgraph[e.to][e.rev].cap += d;\n\
    \t\t\t\t\treturn d;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn 0;\n\t}\n\npublic:\n\
    \tdinic(int v = 0) : INF(std::numeric_limits<flow_t>::max()), graph(v) {}\n\n\t\
    void add_edge(int from, int to, flow_t cap, int idx = -1) {\n\t\tgraph[from].emplace_back(edge{to,\
    \ cap, int(graph[to].size()), false, idx});\n\t\tgraph[to].emplace_back(edge{from,\
    \ 0, int(graph[from].size()) - 1, true, idx});\n\t}\n\n\tflow_t max_flow(int s,\
    \ int t) {\n\t\tflow_t flow = 0;\n\t\twhile(bfs(s, t)) {\n\t\t\titer.assign(graph.size(),\
    \ 0);\n\t\t\tflow_t f = 0;\n\t\t\twhile((f = dfs(s, t, INF)) > 0) flow += f;\n\
    \t\t}\n\t\treturn flow;\n\t}\n\n\tvoid output() {\n\t\tfor(int i = 0; i < (int)graph.size();\
    \ i++) {\n\t\t\tfor(auto &e : graph[i]) {\n\t\t\t\tif(e.isrev) continue;\n\t\t\
    \t\tauto &rev_e = graph[e.to][e.rev];\n\t\t\t\tstd::cout << i << \"->\" << e.to\
    \ << \" (flow:\" << rev_e.cap << \"/\" << e.cap + rev_e.cap << \")\\n\";\n\t\t\
    \t}\n\t\t}\n\t}\n\n\tvoid resize(int x) { graph.resize(x); }\n\n\tint size() {\
    \ return graph.size(); }\n};\n\ntemplate <typename T>\nstruct project_selection_problem\
    \ {\nprivate:\n\tint n;\n\tconst T INF;\n\tT res = 0;\n\tdinic<T> mf;\n\npublic:\n\
    \tproject_selection_problem(int n_) : n(n_), INF(std::numeric_limits<T>::max()),\
    \ mf(n + 2) {}\n\n\tvoid x_and_noty_loss(int x, int y, T loss) {\n\t\tassert(loss\
    \ >= 0);\n\t\tmf.add_edge(x, y, loss);\n\t}\n\n\tvoid x_xor_y_loss(int x, int\
    \ y, T loss) {\n\t\tx_and_noty_loss(x, y, loss);\n\t\tx_and_noty_loss(y, x, loss);\n\
    \t}\n\n\tvoid x_get(int x, T get) {\n\t\tif(get < 0) {\n\t\t\tmf.add_edge(x, n\
    \ + 1, -get);\n\t\t\treturn;\n\t\t}\n\t\tres += get;\n\t\tnotx_loss(x, get);\n\
    \t}\n\n\tvoid x_loss(int x, T loss) {\n\t\tif(loss < 0) {\n\t\t\tx_get(x, -loss);\n\
    \t\t\treturn;\n\t\t}\n\t\tmf.add_edge(x, n + 1, loss);\n\t}\n\n\tvoid notx_get(int\
    \ x, T get) {\n\t\tif(get < 0) {\n\t\t\tmf.add_edge(n, x, -get);\n\t\t\treturn;\n\
    \t\t}\n\t\tres += get;\n\t\tx_loss(x, get);\n\t}\n\n\tvoid notx_loss(int x, T\
    \ loss) {\n\t\tif(loss < 0) {\n\t\t\tnotx_get(x, -loss);\n\t\t\treturn;\n\t\t\
    }\n\t\tmf.add_edge(n, x, loss);\n\t}\n\n\tvoid x_and_y_get(int x, int y, T get)\
    \ {\n\t\tassert(get >= 0);\n\t\tres += get;\n\t\tmf.resize(mf.size() + 1);\n\t\
    \tint w = mf.size() - 1;\n\t\tmf.add_edge(n, w, get);\n\t\tmf.add_edge(w, x, INF);\n\
    \t\tmf.add_edge(w, y, INF);\n\t}\n\n\tvoid x_nor_y_get(int x, int y, T get) {\n\
    \t\tassert(get >= 0);\n\t\tres += get;\n\t\tmf.resize(mf.size() + 1);\n\t\tint\
    \ w = mf.size() - 1;\n\t\tmf.add_edge(w, n + 1, get);\n\t\tmf.add_edge(x, w, INF);\n\
    \t\tmf.add_edge(y, w, INF);\n\t}\n\n\tvoid x_equal_y_get(int x, int y, T get)\
    \ {\n\t\tx_and_y_get(x, y, get);\n\t\tx_nor_y_get(x, y, get);\n\t}\n\n\tT min_lost()\
    \ {\n\t\treturn mf.max_flow(n, n + 1) - res;\n\t}\n\n\tT max_profit() {\n\t\t\
    return -min_lost();\n\t}\n};\n}  // namespace project_selection_problem_impl\n\
    \nusing project_selection_problem_impl::project_selection_problem;\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <cassert>\n#include <iostream>\n\
    #include <limits>\n#include <queue>\n#include <vector>\n\nnamespace project_selection_problem_impl\
    \ {\n\ntemplate <typename flow_t>\nstruct dinic {\nprivate:\n\tconst flow_t INF;\n\
    \tstruct edge {\n\t\tint to;\n\t\tflow_t cap;\n\t\tint rev;\n\t\tbool isrev;\n\
    \t\tint idx;\n\t};\n\tstd::vector<std::vector<edge>> graph;\n\tstd::vector<int>\
    \ min_cost, iter;\n\n\tbool bfs(int s, int t) {\n\t\tmin_cost.assign(graph.size(),\
    \ -1);\n\t\tstd::queue<int> que;\n\t\tmin_cost[s] = 0;\n\t\tque.push(s);\n\t\t\
    while(!que.empty() and min_cost[t] == -1) {\n\t\t\tint p = que.front();\n\t\t\t\
    que.pop();\n\t\t\tfor(auto &e : graph[p]) {\n\t\t\t\tif(e.cap > 0 and min_cost[e.to]\
    \ == -1) {\n\t\t\t\t\tmin_cost[e.to] = min_cost[p] + 1;\n\t\t\t\t\tque.push(e.to);\n\
    \t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn min_cost[t] != -1;\n\t}\n\n\tflow_t dfs(int\
    \ idx, const int t, flow_t flow) {\n\t\tif(idx == t) return flow;\n\t\tfor(int\
    \ &i = iter[idx]; i < SZ(graph[idx]); i++) {\n\t\t\tedge &e = graph[idx][i];\n\
    \t\t\tif(e.cap > 0 and min_cost[idx] < min_cost[e.to]) {\n\t\t\t\tflow_t d = dfs(e.to,\
    \ t, min(flow, e.cap));\n\t\t\t\tif(d > 0) {\n\t\t\t\t\te.cap -= d;\n\t\t\t\t\t\
    graph[e.to][e.rev].cap += d;\n\t\t\t\t\treturn d;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\
    \t\treturn 0;\n\t}\n\npublic:\n\tdinic(int v = 0) : INF(std::numeric_limits<flow_t>::max()),\
    \ graph(v) {}\n\n\tvoid add_edge(int from, int to, flow_t cap, int idx = -1) {\n\
    \t\tgraph[from].emplace_back(edge{to, cap, int(graph[to].size()), false, idx});\n\
    \t\tgraph[to].emplace_back(edge{from, 0, int(graph[from].size()) - 1, true, idx});\n\
    \t}\n\n\tflow_t max_flow(int s, int t) {\n\t\tflow_t flow = 0;\n\t\twhile(bfs(s,\
    \ t)) {\n\t\t\titer.assign(graph.size(), 0);\n\t\t\tflow_t f = 0;\n\t\t\twhile((f\
    \ = dfs(s, t, INF)) > 0) flow += f;\n\t\t}\n\t\treturn flow;\n\t}\n\n\tvoid output()\
    \ {\n\t\tfor(int i = 0; i < (int)graph.size(); i++) {\n\t\t\tfor(auto &e : graph[i])\
    \ {\n\t\t\t\tif(e.isrev) continue;\n\t\t\t\tauto &rev_e = graph[e.to][e.rev];\n\
    \t\t\t\tstd::cout << i << \"->\" << e.to << \" (flow:\" << rev_e.cap << \"/\"\
    \ << e.cap + rev_e.cap << \")\\n\";\n\t\t\t}\n\t\t}\n\t}\n\n\tvoid resize(int\
    \ x) { graph.resize(x); }\n\n\tint size() { return graph.size(); }\n};\n\ntemplate\
    \ <typename T>\nstruct project_selection_problem {\nprivate:\n\tint n;\n\tconst\
    \ T INF;\n\tT res = 0;\n\tdinic<T> mf;\n\npublic:\n\tproject_selection_problem(int\
    \ n_) : n(n_), INF(std::numeric_limits<T>::max()), mf(n + 2) {}\n\n\tvoid x_and_noty_loss(int\
    \ x, int y, T loss) {\n\t\tassert(loss >= 0);\n\t\tmf.add_edge(x, y, loss);\n\t\
    }\n\n\tvoid x_xor_y_loss(int x, int y, T loss) {\n\t\tx_and_noty_loss(x, y, loss);\n\
    \t\tx_and_noty_loss(y, x, loss);\n\t}\n\n\tvoid x_get(int x, T get) {\n\t\tif(get\
    \ < 0) {\n\t\t\tmf.add_edge(x, n + 1, -get);\n\t\t\treturn;\n\t\t}\n\t\tres +=\
    \ get;\n\t\tnotx_loss(x, get);\n\t}\n\n\tvoid x_loss(int x, T loss) {\n\t\tif(loss\
    \ < 0) {\n\t\t\tx_get(x, -loss);\n\t\t\treturn;\n\t\t}\n\t\tmf.add_edge(x, n +\
    \ 1, loss);\n\t}\n\n\tvoid notx_get(int x, T get) {\n\t\tif(get < 0) {\n\t\t\t\
    mf.add_edge(n, x, -get);\n\t\t\treturn;\n\t\t}\n\t\tres += get;\n\t\tx_loss(x,\
    \ get);\n\t}\n\n\tvoid notx_loss(int x, T loss) {\n\t\tif(loss < 0) {\n\t\t\t\
    notx_get(x, -loss);\n\t\t\treturn;\n\t\t}\n\t\tmf.add_edge(n, x, loss);\n\t}\n\
    \n\tvoid x_and_y_get(int x, int y, T get) {\n\t\tassert(get >= 0);\n\t\tres +=\
    \ get;\n\t\tmf.resize(mf.size() + 1);\n\t\tint w = mf.size() - 1;\n\t\tmf.add_edge(n,\
    \ w, get);\n\t\tmf.add_edge(w, x, INF);\n\t\tmf.add_edge(w, y, INF);\n\t}\n\n\t\
    void x_nor_y_get(int x, int y, T get) {\n\t\tassert(get >= 0);\n\t\tres += get;\n\
    \t\tmf.resize(mf.size() + 1);\n\t\tint w = mf.size() - 1;\n\t\tmf.add_edge(w,\
    \ n + 1, get);\n\t\tmf.add_edge(x, w, INF);\n\t\tmf.add_edge(y, w, INF);\n\t}\n\
    \n\tvoid x_equal_y_get(int x, int y, T get) {\n\t\tx_and_y_get(x, y, get);\n\t\
    \tx_nor_y_get(x, y, get);\n\t}\n\n\tT min_lost() {\n\t\treturn mf.max_flow(n,\
    \ n + 1) - res;\n\t}\n\n\tT max_profit() {\n\t\treturn -min_lost();\n\t}\n};\n\
    }  // namespace project_selection_problem_impl\n\nusing project_selection_problem_impl::project_selection_problem;\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/project_selection_problem.hpp
  requiredBy: []
  timestamp: '2021-10-30 20:59:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/project_selection_problem.hpp
layout: document
redirect_from:
- /library/graph/project_selection_problem.hpp
- /library/graph/project_selection_problem.hpp.html
title: graph/project_selection_problem.hpp
---
