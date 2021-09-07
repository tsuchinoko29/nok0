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
  bundledCode: "#line 1 \"data_structure/trie.hpp\"\n#include <functional>\n#include\
    \ <string>\n#include <vector>\n\ntemplate <int char_size = 26, int margin = 'a'>\n\
    struct Trie {\nprivate:\n\tstruct Node {\n\t\tstd::vector<int> nxt, accept;\n\t\
    \tint exist;\n\t\tNode() : exist(0), nxt(char_size, -1) {}\n\t};\n\tstd::vector<Node>\
    \ nodes;\n\tint root;\n\n\tvoid update_direct(const int node, const int id) {\n\
    \t\tnodes[node].accept.push_back(id);\n\t}\n\n\tvoid update_child(const int node,\
    \ const int child, const int id) {\n\t\t++nodes[node].exist;\n\t}\n\n\tvoid add(const\
    \ std::string &s, const int str_index, const int node_index, const int id) {\n\
    \t\tif(str_index == s.length())\n\t\t\tupdate_direct(node_index, id);\n\t\telse\
    \ {\n\t\t\tconst int c = s[str_index] - margin;\n\t\t\tif(nodes[node_index].nxt[c]\
    \ == -1) {\n\t\t\t\tnodes[node_index].nxt[c] = nodes.size();\n\t\t\t\tnodes.push_back(Node());\n\
    \t\t\t}\n\t\t\tadd(s, str_index + 1, nodes[node_index].nxt[c], id);\n\t\t\tupdate_child(node_index,\
    \ nodes[node_index].nxt[c], id);\n\t\t}\n\t}\n\n\tvoid query(const std::string\
    \ &s, const std::function<void(int)> &f, int str_index, int node_index) {\n\t\t\
    for(auto &idx : nodes[node_index].accept) f(idx);\n\t\tif(str_index == s.length())\
    \ {\n\t\t\treturn;\n\t\t} else {\n\t\t\tconst int c = s[str_index] - margin;\n\
    \t\t\tif(nodes[node_index].nxt[c] == -1) return;\n\t\t\tquery(s, f, str_index\
    \ + 1, nodes[node_index].nxt[c]);\n\t\t}\n\t}\n\npublic:\n\tTrie() : root(0) {\n\
    \t\tnodes.push_back(Node());\n\t}\n\n\tvoid add(const std::string &s) {\n\t\t\
    add(s, 0, 0, nodes[0].exist);\n\t}\n\n\tvoid query(const std::string &s, const\
    \ std::function<void(int)> &f) {\n\t\tquery(s, f, 0, 0);\n\t}\n\n\tint count()\
    \ const { return (nodes[0].exist); }\n\n\tint size() const { return ((int)nodes.size());\
    \ }\n};\n"
  code: "#include <functional>\n#include <string>\n#include <vector>\n\ntemplate <int\
    \ char_size = 26, int margin = 'a'>\nstruct Trie {\nprivate:\n\tstruct Node {\n\
    \t\tstd::vector<int> nxt, accept;\n\t\tint exist;\n\t\tNode() : exist(0), nxt(char_size,\
    \ -1) {}\n\t};\n\tstd::vector<Node> nodes;\n\tint root;\n\n\tvoid update_direct(const\
    \ int node, const int id) {\n\t\tnodes[node].accept.push_back(id);\n\t}\n\n\t\
    void update_child(const int node, const int child, const int id) {\n\t\t++nodes[node].exist;\n\
    \t}\n\n\tvoid add(const std::string &s, const int str_index, const int node_index,\
    \ const int id) {\n\t\tif(str_index == s.length())\n\t\t\tupdate_direct(node_index,\
    \ id);\n\t\telse {\n\t\t\tconst int c = s[str_index] - margin;\n\t\t\tif(nodes[node_index].nxt[c]\
    \ == -1) {\n\t\t\t\tnodes[node_index].nxt[c] = nodes.size();\n\t\t\t\tnodes.push_back(Node());\n\
    \t\t\t}\n\t\t\tadd(s, str_index + 1, nodes[node_index].nxt[c], id);\n\t\t\tupdate_child(node_index,\
    \ nodes[node_index].nxt[c], id);\n\t\t}\n\t}\n\n\tvoid query(const std::string\
    \ &s, const std::function<void(int)> &f, int str_index, int node_index) {\n\t\t\
    for(auto &idx : nodes[node_index].accept) f(idx);\n\t\tif(str_index == s.length())\
    \ {\n\t\t\treturn;\n\t\t} else {\n\t\t\tconst int c = s[str_index] - margin;\n\
    \t\t\tif(nodes[node_index].nxt[c] == -1) return;\n\t\t\tquery(s, f, str_index\
    \ + 1, nodes[node_index].nxt[c]);\n\t\t}\n\t}\n\npublic:\n\tTrie() : root(0) {\n\
    \t\tnodes.push_back(Node());\n\t}\n\n\tvoid add(const std::string &s) {\n\t\t\
    add(s, 0, 0, nodes[0].exist);\n\t}\n\n\tvoid query(const std::string &s, const\
    \ std::function<void(int)> &f) {\n\t\tquery(s, f, 0, 0);\n\t}\n\n\tint count()\
    \ const { return (nodes[0].exist); }\n\n\tint size() const { return ((int)nodes.size());\
    \ }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/trie.hpp
  requiredBy: []
  timestamp: '2021-09-07 20:08:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/trie.hpp
layout: document
redirect_from:
- /library/data_structure/trie.hpp
- /library/data_structure/trie.hpp.html
title: data_structure/trie.hpp
---
