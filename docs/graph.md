## グラフ構造体
グラフの様々なアルゴリズムを扱うライブラリです。

### 初めに
$V$ はグラフの頂点数、 $E$ はグラフの辺数を表します,
制約に違反する操作を行った場合の動作は未定義です.
計算量はお気持ちです.

#### INFの取り扱いについて
`INF` は非常に大きい数 $(3×10^{18})$ で代用しています.値を取得したい場合, `.INF` で取り出せます.
答えの絶対値が `INF` を超えるような場合の動作も未定義です.

### コンストラクタ

```cpp
(1) Graph g(int n);
```
$n$ 頂点 $0$ 辺のグラフを作ります。
##### 制約
- $0 \le n \le 10^8 $
##### 計算量
- $Ο(n)$

```cpp
(2) Graph g(int n, int e = -1,  bool weight = 0, bool directed = 0, int idx = 1);
```
$n$ 頂点 $0$ 辺のグラフを作った後,辺を $e$ 本受け取ります. $e = -1$ のときは、 $n-1$ 本受け取ります.(木の場合等)

`weight`で入力する辺が重み付きかどうかを,`directed`で有向辺かどうかを,`idx`で入力のインデックスが $0$ か $1$ かを指定します.

`weight` = False の場合, 以下のような入力形式を想定しています.
>
>$u_1\ v_1$
>$u_2\ v_2$
>$\vdots$
>$u_e\ v_e$
>

`weight` = True の場合, 以下のような入力形式を想定しています.
>
>$u_1\ v_1\ c_1$
>$u_2\ v_2\ c_2$
>$\vdots$
>$u_e\ v_e\ c_e$
>

##### 制約
- $0 \le n, e  \le 10^8 $
##### 計算量
- $Ο(n + e)$

### input
```cpp
void g.input(int e = -1, bool weight = 0, bool directed = false, int idx = 1);
```
辺を $e$ 本受け取ります.仕様はコンストラクタ(2)と同様です.
##### 制約
- $0 \le e  \le 10^8 $
##### 計算量
- $Ο(e)$
### add_edge
```cpp
void g.add_edge(int u, int v, long long cost = 1, bool directed = false, int idx = 0);
```
頂点 $u,v$ を結ぶ辺を作成します.
`cost`で辺のcost,`directed`で有向辺か,`idx`で入力のインデックスを指定します.
##### 制約
- $0 \le u- \mathrm{idx} , v-\mathrm{idx} < n $
- `cost` は `long long`
##### 計算量
- $Ο(1)$
### bfs
```cpp
std::vector<long long> g.bfs(int s);
```
頂点 $s$ から各頂点への最短距離をbfsを用いて求め,その配列を返します. $s$ から到達不可能な頂点には `INF` の値が割り当てられます.
##### 制約
- グラフの全ての辺のコストが等しいか,グラフが木
- $0 \le s < V$
##### 計算量
- $Ο(V + E)$

### zero_one_bfs
```cpp
std::vector<long long> g.zero_one_bfs(int s);
```
頂点 $s$ から各頂点への最短距離を01-bfsを用いて求め,その配列を返します. $s$ から到達不可能な頂点には `INF` の値が割り当てられます.
##### 制約
- グラフの全ての辺のコストが $0$ もしくは $1$
- $0 \le s < V$
##### 計算量
- $Ο(V + E)$

### dijkstra
```cpp
std::vector<long long> g.dijkstra(int s);
```
頂点 $s$ から各頂点への最短距離をdijkstra法を用いて求め,その配列を返します. $s$ から到達不可能な頂点には `INF` の値が割り当てられます.
##### 制約
- グラフの全ての辺のコストが非負
- $0 \le s < V$
##### 計算量
- $Ο((V+E)\log V)$

### bellman_ford
```cpp
std::vector<long long> g.bellman_ford(int s);
```
頂点 $s$ から各頂点への最短距離をbellman_ford法を用いて求め,その配列を返します. $s$ から到達不可能な頂点には `INF` の値が割り当てられます. $s$ から到達可能でかつ負閉路から辿り着ける頂点には `-INF` の値が割り当てられます,
##### 制約
- $0 \le s < V$
##### 計算量
- $Ο(VE)$

### warshall_floyd
```cpp
std::vector<std::vector<long long>> g.warshall_floyd();
```
全頂点間距離をwarshall_floyd法を使って求め,その配列を返します. 到達不可能な頂点には `INF` の値が割り当てられます.
##### 制約
- グラフの全ての辺のコストが非負
##### 計算量
- $Ο(V^3)$

### topological_sort
```cpp
std::vector<int> g.topological_sort();
```
頂点をトポロジカルソート順に並べた配列を返します.もしトポロジカルソートが不可能な場合, 代わりに空配列`{}`を返します.
##### 制約
- 無し
##### 計算量
- $Ο(V + E)$

### is_DAG
```cpp
bool g.is_DAG();
```
グラフがDAGの場合 `True` を, そうでない時 `False` を返します.
##### 制約
- 無し
##### 計算量
- $Ο(V + E)$

### height
```cpp
std::vector<long long> g.height();
```
頂点から最遠点までの距離を各頂点について求め,配列で返します.

##### 制約
- グラフが木
##### 計算量
- $Ο(V + E)$

### bipartite_grouping
```cpp
std::vector<int> g.bipartite_grouping();
```
二部グラフの割り当て方を実際に一つ構成し、それを配列で返します.各頂点には $0$ か $1$ が割り当てられます.
もしグラフが二部グラフでない時、代わりに空配列`{}`を返します.
##### 制約
- グラフが無向
##### 計算量
- $Ο(V + E)$

### is_bipartite
```cpp
bool g.is_bipartite();
```
グラフが二部グラフの場合 `True` を, そうでない時 `False` を返します.
##### 制約
- グラフが無向
##### 計算量
- $Ο(V + E)$

### diameter
```cpp
std::pair<std::pair<int, int>, long long> g.diameter();
```
グラフの直径を求め,直径の端点2つと直径のペアを返します.
##### 制約
- グラフの全ての辺のコストが非負
##### 計算量
- $Ο(V + E)$

### prim
```cpp
long long g.prim();
```
prim法を用いて最小全域木のコストを求め,その値を返します.
##### 制約
- グラフが無向
##### 計算量
- $Ο(E\log V)$

### kruskal
```cpp
long long g.kruskal();
```
kruskal法を用いて最小全域木のコストを求め,その値を返します.
##### 制約
- グラフが無向
##### 計算量
- $Ο(E\log V)$

### centroid
```cpp
std::vector<int> g.centroid();
```
木の重心を求め,木の重心が入った配列を返します.
ここで,木の重心の個数は $1$ つまたは $2$ つであることが保証されるので, 配列のサイズも必ず $1$ もしくは $2$ です.
##### 制約
- グラフが木
##### 計算量
- $Ο(V + E)$

### bridges_and_articulations
```cpp
std::pair<std::vector<std::pair<int, int>>, std::vector<int>> g.bridges_and_articulations();
```
lowlinkを用いて橋と関節点を求め,橋の配列と関節点の配列のペアで返します. 橋に関しては辺の番号が入っているわけではなく,各橋についてその橋が結ぶ二頂点が入っていることに注意してください.

##### 制約
- グラフが木
##### 計算量
- $Ο(V + E)$

### root_to_leaf
```cpp
Graph g.root_to_leaf(int root = 0);
```
`root`を根とした有向dfs木を返します.辺の向きは根から葉へと伸びる方向です.

##### 制約
- グラフが無向
- $0 \le \mathrm{root} < V$
##### 計算量
- $Ο(V + E)$

### leaf_to_root
```cpp
Graph g.leaf_to_root(int root = 0);
```
`root`を根とした有向dfs木を返します.辺の向きは葉から根へと伸びる方向です.

##### 制約
- グラフが無向
- $0 \le \mathrm{root} < V$
##### 計算量
- $Ο(V + E)$

## tree_doubling
lowest common ancestor や level ancestor等を扱う構造体です. グラフを渡して使用します.
### コンストラクタ
```cpp
tree_doubling td(const Graph &g, const int root = 0);
```
`root`を根として前計算を行います.
##### 制約
- グラフが木
- $0 \le \mathrm{root} < V$
##### 計算量
- $Ο(V\log V)$

### lowest_common_ancestor
```cpp
int td.lowest_common_ancestor(int u, int v);
```
頂点 $u$ と $v$ の最小共通祖先を返します.
##### 制約
- $0 \le u, v < V$
##### 計算量
- $Ο(\log V)$

###  length_of_path
```cpp
long long td.length_of_path(const int u, const int v);
```
頂点 $u,v$ 間の距離を返します.
##### 制約
- $0 \le u, v < V$
##### 計算量
- $Ο(\log V)$

###  level_ancestor
```cpp
int td.level_ancestor(int v, int level);
```
頂点 $v$ から `level` の数だけ辺を遡った頂点を返します. そのような頂点が存在しない場合, `root` を返します.
##### 制約
- $0 \le  v < V$
- `level` は非負
##### 計算量
- $Ο(\log V)$

## strongly_connected_components
後ほど追記します.

## heavy_light_decomposition
後ほど追記します.