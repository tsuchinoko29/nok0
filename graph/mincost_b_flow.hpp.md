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
  bundledCode: "#line 1 \"graph/mincost_b_flow.hpp\"\n#include <algorithm>\n#include\
    \ <cassert>\n#include <cstdint>\n#include <numeric>\n#include <queue>\n#include\
    \ <vector>\n\nenum Objective {\n\tMINIMIZE = 1,\n\tMAXIMIZE = -1,\n};\nenum class\
    \ Status {\n\tOPTIMAL,\n\tINFEASIBLE,\n};\n\ntemplate <class Flow, class Cost,\
    \ Objective objective = Objective::MINIMIZE, Flow SCALING_FACTOR = 2>\nstruct\
    \ MinCostFlow {\nprivate:\n\tusing V_id = uint32_t;\n\tusing E_id = uint32_t;\n\
    \n\tstruct Edge {\n\t\tfriend struct MinCostFlow;\n\n\tprivate:\n\t\tV_id src,\
    \ dst;\n\t\tFlow flow, cap;\n\t\tCost cost;\n\t\tE_id rev;\n\n\tpublic:\n\t\t\
    Edge() = default;\n\n\t\tEdge(const V_id src, const V_id dst, const Flow cap,\
    \ const Cost cost,\n\t\t     const E_id rev)\n\t\t  : src(src), dst(dst), flow(0),\
    \ cap(cap), cost(cost), rev(rev) {}\n\n\t\t[[nodiscard]] Flow residual_cap() const\
    \ { return cap - flow; }\n\t};\n\npublic:\n\tstruct EdgePtr {\n\t\tfriend struct\
    \ MinCostFlow;\n\n\tprivate:\n\t\tconst MinCostFlow *instance;\n\t\tconst V_id\
    \ v;\n\t\tconst E_id e;\n\n\t\tEdgePtr(const MinCostFlow *instance, const V_id\
    \ v, const E_id e)\n\t\t  : instance(instance), v(v), e(e) {}\n\n\t\t[[nodiscard]]\
    \ const Edge &edge() const { return instance->g[v][e]; }\n\n\t\t[[nodiscard]]\
    \ const Edge &rev() const {\n\t\t\tconst Edge &e = edge();\n\t\t\treturn instance->g[e.dst][e.rev];\n\
    \t\t}\n\n\tpublic:\n\t\t[[nodiscard]] V_id src() const { return rev().dst; }\n\
    \n\t\t[[nodiscard]] V_id dst() const { return edge().dst; }\n\n\t\t[[nodiscard]]\
    \ Flow flow() const { return edge().flow; }\n\n\t\t[[nodiscard]] Flow lower()\
    \ const { return -rev().cap; }\n\n\t\t[[nodiscard]] Flow upper() const { return\
    \ edge().cap; }\n\n\t\t[[nodiscard]] Cost cost() const { return edge().cost; }\n\
    \n\t\t[[nodiscard]] Cost gain() const { return -edge().cost; }\n\t};\n\nprivate:\n\
    \tV_id n;\n\tstd::vector<std::vector<Edge>> g;\n\tstd::vector<Flow> b;\n\npublic:\n\
    \tMinCostFlow() : n(0) {}\n\n\tV_id add_vertex() {\n\t\t++n;\n\t\tg.resize(n);\n\
    \t\tb.resize(n);\n\t\treturn n - 1;\n\t}\n\n\tstd::vector<V_id> add_vertices(const\
    \ size_t size) {\n\t\tstd::vector<V_id> ret;\n\t\tfor(V_id i = 0; i < size; ++i)\
    \ ret.emplace_back(n + i);\n\t\tn += size;\n\t\tg.resize(n);\n\t\tb.resize(n);\n\
    \t\treturn ret;\n\t}\n\n\tEdgePtr add_edge(const V_id src, const V_id dst, const\
    \ Flow lower, const Flow upper, const Cost cost) {\n\t\tconst E_id e = g[src].size(),\
    \ re = src == dst ? e + 1 : g[dst].size();\n\t\tassert(lower <= upper);\n\t\t\
    g[src].emplace_back(Edge{src, dst, upper, cost * objective, re});\n\t\tg[dst].emplace_back(Edge{dst,\
    \ src, -lower, -cost * objective, e});\n\t\treturn EdgePtr{this, src, e};\n\t\
    }\n\n\tvoid add_supply(const V_id v, const Flow amount) { b[v] += amount; }\n\n\
    \tvoid add_demand(const V_id v, const Flow amount) { b[v] -= amount; }\n\nprivate:\n\
    \tstatic Cost constexpr unreachable = std::numeric_limits<Cost>::max();\n\tCost\
    \ farthest;\n\tstd::vector<Cost> potential;\n\tstd::vector<Cost> dist;\n\tstd::vector<Edge\
    \ *> parent;\n\tstd::priority_queue<std::pair<Cost, int>, std::vector<std::pair<Cost,\
    \ int>>, std::greater<>> pq;\n\tstd::vector<V_id> excess_vs, deficit_vs;\n\n\t\
    Edge &rev(const Edge &e) { return g[e.dst][e.rev]; }\n\n\tvoid push(Edge &e, const\
    \ Flow amount) {\n\t\te.flow += amount;\n\t\tg[e.dst][e.rev].flow -= amount;\n\
    \t}\n\n\tCost residual_cost(const V_id src, const V_id dst, const Edge &e) {\n\
    \t\treturn e.cost + potential[src] - potential[dst];\n\t}\n\n\tbool dual(const\
    \ Flow delta) {\n\t\tdist.assign(n, unreachable);\n\t\tparent.assign(n, nullptr);\n\
    \t\texcess_vs.erase(std::remove_if(std::begin(excess_vs), std::end(excess_vs),\
    \ [&](const V_id v) { return b[v] < delta; }), std::end(excess_vs));\n\t\tdeficit_vs.erase(std::remove_if(std::begin(deficit_vs),\
    \ std::end(deficit_vs), [&](const V_id v) { return b[v] > -delta; }), std::end(deficit_vs));\n\
    \t\tfor(const auto v : excess_vs) pq.emplace(dist[v] = 0, v);\n\t\tfarthest =\
    \ 0;\n\t\tstd::size_t deficit_count = 0;\n\t\twhile(!pq.empty()) {\n\t\t\tconst\
    \ auto [d, u] = pq.top();\n\t\t\tpq.pop();\n\t\t\tif(dist[u] < d) continue;\n\t\
    \t\tfarthest = d;\n\t\t\tif(b[u] <= -delta) ++deficit_count;\n\t\t\tif(deficit_count\
    \ >= deficit_vs.size()) break;\n\t\t\tfor(auto &e : g[u]) {\n\t\t\t\tif(e.residual_cap()\
    \ < delta) continue;\n\t\t\t\tconst auto v = e.dst;\n\t\t\t\tconst auto new_dist\
    \ = d + residual_cost(u, v, e);\n\t\t\t\tif(new_dist >= dist[v]) continue;\n\t\
    \t\t\tpq.emplace(dist[v] = new_dist, v);\n\t\t\t\tparent[v] = &e;\n\t\t\t}\n\t\
    \t}\n\t\tpq = decltype(pq)();\n\t\tfor(V_id v = 0; v < n; ++v) {\n\t\t\tpotential[v]\
    \ += std::min(dist[v], farthest);\n\t\t}\n\t\treturn deficit_count > 0;\n\t}\n\
    \n\tvoid primal(const Flow delta) {\n\t\tfor(const auto t : deficit_vs) {\n\t\t\
    \tif(dist[t] > farthest) continue;\n\t\t\tFlow f = -b[t];\n\t\t\tV_id v;\n\t\t\
    \tfor(v = t; parent[v] != nullptr && f >= delta; v = parent[v]->src) {\n\t\t\t\
    \tf = std::min(f, parent[v]->residual_cap());\n\t\t\t}\n\t\t\tf = std::min(f,\
    \ b[v]);\n\t\t\tif(f < delta) continue;\n\t\t\tfor(v = t; parent[v] != nullptr;)\
    \ {\n\t\t\t\tauto &e = *parent[v];\n\t\t\t\tpush(e, f);\n\t\t\t\tconst size_t\
    \ u = parent[v]->src;\n\t\t\t\tparent[v] = nullptr;\n\t\t\t\tv = u;\n\t\t\t}\n\
    \t\t\tb[t] += f;\n\t\t\tb[v] -= f;\n\t\t}\n\t}\n\n\tvoid saturate_negative(const\
    \ Flow delta) {\n\t\texcess_vs.clear();\n\t\tdeficit_vs.clear();\n\t\tfor(auto\
    \ &es : g)\n\t\t\tfor(auto &e : es) {\n\t\t\t\tconst Flow rcap = e.residual_cap();\n\
    \t\t\t\tconst Cost rcost = residual_cost(e.src, e.dst, e);\n\t\t\t\tif(rcost <\
    \ 0 && rcap >= delta) {\n\t\t\t\t\tpush(e, rcap);\n\t\t\t\t\tb[e.src] -= rcap;\n\
    \t\t\t\t\tb[e.dst] += rcap;\n\t\t\t\t}\n\t\t\t}\n\t\tfor(V_id v = 0; v < n; ++v)\n\
    \t\t\tif(b[v] != 0) {\n\t\t\t\t(b[v] > 0 ? excess_vs : deficit_vs).emplace_back(v);\n\
    \t\t\t}\n\t}\n\npublic:\n\tstd::pair<Status, Cost> solve() {\n\t\tpotential.resize(n);\n\
    \t\tfor(auto &es : g)\n\t\t\tfor(auto &e : es) {\n\t\t\t\tconst Flow rcap = e.residual_cap();\n\
    \t\t\t\tif(rcap < 0) {\n\t\t\t\t\tpush(e, rcap);\n\t\t\t\t\tb[e.src] -= rcap;\n\
    \t\t\t\t\tb[e.dst] += rcap;\n\t\t\t\t}\n\t\t\t}\n\n\t\tFlow inf_flow = 1;\n\t\t\
    for(const auto &es : g)\n\t\t\tfor(const auto &e : es) inf_flow = std::max(inf_flow,\
    \ e.residual_cap());\n\t\tFlow delta = 1;\n\t\twhile(delta <= inf_flow) delta\
    \ *= SCALING_FACTOR;\n\n\t\tfor(delta /= SCALING_FACTOR; delta; delta /= SCALING_FACTOR)\
    \ {\n\t\t\tsaturate_negative(delta);\n\t\t\twhile(dual(delta)) primal(delta);\n\
    \t\t}\n\n\t\tCost value = 0;\n\t\tfor(const auto &es : g)\n\t\t\tfor(const auto\
    \ &e : es) {\n\t\t\t\tvalue += e.flow * e.cost;\n\t\t\t}\n\t\tvalue /= 2;\n\n\t\
    \tif(excess_vs.empty() && deficit_vs.empty()) {\n\t\t\treturn {Status::OPTIMAL,\
    \ value / objective};\n\t\t} else {\n\t\t\treturn {Status::INFEASIBLE, value /\
    \ objective};\n\t\t}\n\t}\n};\n\ntemplate <class Flow, class Cost>\nusing MaxGainFlow\
    \ = MinCostFlow<Flow, Cost, Objective::MAXIMIZE>;\n"
  code: "#include <algorithm>\n#include <cassert>\n#include <cstdint>\n#include <numeric>\n\
    #include <queue>\n#include <vector>\n\nenum Objective {\n\tMINIMIZE = 1,\n\tMAXIMIZE\
    \ = -1,\n};\nenum class Status {\n\tOPTIMAL,\n\tINFEASIBLE,\n};\n\ntemplate <class\
    \ Flow, class Cost, Objective objective = Objective::MINIMIZE, Flow SCALING_FACTOR\
    \ = 2>\nstruct MinCostFlow {\nprivate:\n\tusing V_id = uint32_t;\n\tusing E_id\
    \ = uint32_t;\n\n\tstruct Edge {\n\t\tfriend struct MinCostFlow;\n\n\tprivate:\n\
    \t\tV_id src, dst;\n\t\tFlow flow, cap;\n\t\tCost cost;\n\t\tE_id rev;\n\n\tpublic:\n\
    \t\tEdge() = default;\n\n\t\tEdge(const V_id src, const V_id dst, const Flow cap,\
    \ const Cost cost,\n\t\t     const E_id rev)\n\t\t  : src(src), dst(dst), flow(0),\
    \ cap(cap), cost(cost), rev(rev) {}\n\n\t\t[[nodiscard]] Flow residual_cap() const\
    \ { return cap - flow; }\n\t};\n\npublic:\n\tstruct EdgePtr {\n\t\tfriend struct\
    \ MinCostFlow;\n\n\tprivate:\n\t\tconst MinCostFlow *instance;\n\t\tconst V_id\
    \ v;\n\t\tconst E_id e;\n\n\t\tEdgePtr(const MinCostFlow *instance, const V_id\
    \ v, const E_id e)\n\t\t  : instance(instance), v(v), e(e) {}\n\n\t\t[[nodiscard]]\
    \ const Edge &edge() const { return instance->g[v][e]; }\n\n\t\t[[nodiscard]]\
    \ const Edge &rev() const {\n\t\t\tconst Edge &e = edge();\n\t\t\treturn instance->g[e.dst][e.rev];\n\
    \t\t}\n\n\tpublic:\n\t\t[[nodiscard]] V_id src() const { return rev().dst; }\n\
    \n\t\t[[nodiscard]] V_id dst() const { return edge().dst; }\n\n\t\t[[nodiscard]]\
    \ Flow flow() const { return edge().flow; }\n\n\t\t[[nodiscard]] Flow lower()\
    \ const { return -rev().cap; }\n\n\t\t[[nodiscard]] Flow upper() const { return\
    \ edge().cap; }\n\n\t\t[[nodiscard]] Cost cost() const { return edge().cost; }\n\
    \n\t\t[[nodiscard]] Cost gain() const { return -edge().cost; }\n\t};\n\nprivate:\n\
    \tV_id n;\n\tstd::vector<std::vector<Edge>> g;\n\tstd::vector<Flow> b;\n\npublic:\n\
    \tMinCostFlow() : n(0) {}\n\n\tV_id add_vertex() {\n\t\t++n;\n\t\tg.resize(n);\n\
    \t\tb.resize(n);\n\t\treturn n - 1;\n\t}\n\n\tstd::vector<V_id> add_vertices(const\
    \ size_t size) {\n\t\tstd::vector<V_id> ret;\n\t\tfor(V_id i = 0; i < size; ++i)\
    \ ret.emplace_back(n + i);\n\t\tn += size;\n\t\tg.resize(n);\n\t\tb.resize(n);\n\
    \t\treturn ret;\n\t}\n\n\tEdgePtr add_edge(const V_id src, const V_id dst, const\
    \ Flow lower, const Flow upper, const Cost cost) {\n\t\tconst E_id e = g[src].size(),\
    \ re = src == dst ? e + 1 : g[dst].size();\n\t\tassert(lower <= upper);\n\t\t\
    g[src].emplace_back(Edge{src, dst, upper, cost * objective, re});\n\t\tg[dst].emplace_back(Edge{dst,\
    \ src, -lower, -cost * objective, e});\n\t\treturn EdgePtr{this, src, e};\n\t\
    }\n\n\tvoid add_supply(const V_id v, const Flow amount) { b[v] += amount; }\n\n\
    \tvoid add_demand(const V_id v, const Flow amount) { b[v] -= amount; }\n\nprivate:\n\
    \tstatic Cost constexpr unreachable = std::numeric_limits<Cost>::max();\n\tCost\
    \ farthest;\n\tstd::vector<Cost> potential;\n\tstd::vector<Cost> dist;\n\tstd::vector<Edge\
    \ *> parent;\n\tstd::priority_queue<std::pair<Cost, int>, std::vector<std::pair<Cost,\
    \ int>>, std::greater<>> pq;\n\tstd::vector<V_id> excess_vs, deficit_vs;\n\n\t\
    Edge &rev(const Edge &e) { return g[e.dst][e.rev]; }\n\n\tvoid push(Edge &e, const\
    \ Flow amount) {\n\t\te.flow += amount;\n\t\tg[e.dst][e.rev].flow -= amount;\n\
    \t}\n\n\tCost residual_cost(const V_id src, const V_id dst, const Edge &e) {\n\
    \t\treturn e.cost + potential[src] - potential[dst];\n\t}\n\n\tbool dual(const\
    \ Flow delta) {\n\t\tdist.assign(n, unreachable);\n\t\tparent.assign(n, nullptr);\n\
    \t\texcess_vs.erase(std::remove_if(std::begin(excess_vs), std::end(excess_vs),\
    \ [&](const V_id v) { return b[v] < delta; }), std::end(excess_vs));\n\t\tdeficit_vs.erase(std::remove_if(std::begin(deficit_vs),\
    \ std::end(deficit_vs), [&](const V_id v) { return b[v] > -delta; }), std::end(deficit_vs));\n\
    \t\tfor(const auto v : excess_vs) pq.emplace(dist[v] = 0, v);\n\t\tfarthest =\
    \ 0;\n\t\tstd::size_t deficit_count = 0;\n\t\twhile(!pq.empty()) {\n\t\t\tconst\
    \ auto [d, u] = pq.top();\n\t\t\tpq.pop();\n\t\t\tif(dist[u] < d) continue;\n\t\
    \t\tfarthest = d;\n\t\t\tif(b[u] <= -delta) ++deficit_count;\n\t\t\tif(deficit_count\
    \ >= deficit_vs.size()) break;\n\t\t\tfor(auto &e : g[u]) {\n\t\t\t\tif(e.residual_cap()\
    \ < delta) continue;\n\t\t\t\tconst auto v = e.dst;\n\t\t\t\tconst auto new_dist\
    \ = d + residual_cost(u, v, e);\n\t\t\t\tif(new_dist >= dist[v]) continue;\n\t\
    \t\t\tpq.emplace(dist[v] = new_dist, v);\n\t\t\t\tparent[v] = &e;\n\t\t\t}\n\t\
    \t}\n\t\tpq = decltype(pq)();\n\t\tfor(V_id v = 0; v < n; ++v) {\n\t\t\tpotential[v]\
    \ += std::min(dist[v], farthest);\n\t\t}\n\t\treturn deficit_count > 0;\n\t}\n\
    \n\tvoid primal(const Flow delta) {\n\t\tfor(const auto t : deficit_vs) {\n\t\t\
    \tif(dist[t] > farthest) continue;\n\t\t\tFlow f = -b[t];\n\t\t\tV_id v;\n\t\t\
    \tfor(v = t; parent[v] != nullptr && f >= delta; v = parent[v]->src) {\n\t\t\t\
    \tf = std::min(f, parent[v]->residual_cap());\n\t\t\t}\n\t\t\tf = std::min(f,\
    \ b[v]);\n\t\t\tif(f < delta) continue;\n\t\t\tfor(v = t; parent[v] != nullptr;)\
    \ {\n\t\t\t\tauto &e = *parent[v];\n\t\t\t\tpush(e, f);\n\t\t\t\tconst size_t\
    \ u = parent[v]->src;\n\t\t\t\tparent[v] = nullptr;\n\t\t\t\tv = u;\n\t\t\t}\n\
    \t\t\tb[t] += f;\n\t\t\tb[v] -= f;\n\t\t}\n\t}\n\n\tvoid saturate_negative(const\
    \ Flow delta) {\n\t\texcess_vs.clear();\n\t\tdeficit_vs.clear();\n\t\tfor(auto\
    \ &es : g)\n\t\t\tfor(auto &e : es) {\n\t\t\t\tconst Flow rcap = e.residual_cap();\n\
    \t\t\t\tconst Cost rcost = residual_cost(e.src, e.dst, e);\n\t\t\t\tif(rcost <\
    \ 0 && rcap >= delta) {\n\t\t\t\t\tpush(e, rcap);\n\t\t\t\t\tb[e.src] -= rcap;\n\
    \t\t\t\t\tb[e.dst] += rcap;\n\t\t\t\t}\n\t\t\t}\n\t\tfor(V_id v = 0; v < n; ++v)\n\
    \t\t\tif(b[v] != 0) {\n\t\t\t\t(b[v] > 0 ? excess_vs : deficit_vs).emplace_back(v);\n\
    \t\t\t}\n\t}\n\npublic:\n\tstd::pair<Status, Cost> solve() {\n\t\tpotential.resize(n);\n\
    \t\tfor(auto &es : g)\n\t\t\tfor(auto &e : es) {\n\t\t\t\tconst Flow rcap = e.residual_cap();\n\
    \t\t\t\tif(rcap < 0) {\n\t\t\t\t\tpush(e, rcap);\n\t\t\t\t\tb[e.src] -= rcap;\n\
    \t\t\t\t\tb[e.dst] += rcap;\n\t\t\t\t}\n\t\t\t}\n\n\t\tFlow inf_flow = 1;\n\t\t\
    for(const auto &es : g)\n\t\t\tfor(const auto &e : es) inf_flow = std::max(inf_flow,\
    \ e.residual_cap());\n\t\tFlow delta = 1;\n\t\twhile(delta <= inf_flow) delta\
    \ *= SCALING_FACTOR;\n\n\t\tfor(delta /= SCALING_FACTOR; delta; delta /= SCALING_FACTOR)\
    \ {\n\t\t\tsaturate_negative(delta);\n\t\t\twhile(dual(delta)) primal(delta);\n\
    \t\t}\n\n\t\tCost value = 0;\n\t\tfor(const auto &es : g)\n\t\t\tfor(const auto\
    \ &e : es) {\n\t\t\t\tvalue += e.flow * e.cost;\n\t\t\t}\n\t\tvalue /= 2;\n\n\t\
    \tif(excess_vs.empty() && deficit_vs.empty()) {\n\t\t\treturn {Status::OPTIMAL,\
    \ value / objective};\n\t\t} else {\n\t\t\treturn {Status::INFEASIBLE, value /\
    \ objective};\n\t\t}\n\t}\n};\n\ntemplate <class Flow, class Cost>\nusing MaxGainFlow\
    \ = MinCostFlow<Flow, Cost, Objective::MAXIMIZE>;\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/mincost_b_flow.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/mincost_b_flow.hpp
layout: document
redirect_from:
- /library/graph/mincost_b_flow.hpp
- /library/graph/mincost_b_flow.hpp.html
title: graph/mincost_b_flow.hpp
---
