#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

class UnionFind {
 private:
  vector<int> parent;
  vector<int> sz;

 public:
  UnionFind(int node) : sz(node, 1) {
    parent.resize(node);
    for (int i = 0; i < node; ++i) {
      parent[i] = i;
    }
  }

  int root(int x) { return parent[x] == x ? x : parent[x] = root(parent[x]); }
  int size(int x) { return sz[root(x)]; }
  bool is_same(int i, int j) { return root(i) == root(j); }
  void unite(int i, int j) {
    int x = root(i), y = root(j);
    if (x == y) {
      return;
    }
    if (sz[x] < sz[y]) {
      swap(x, y);
    }
    sz[x] += sz[y];
    parent[y] = x;
    return;
  }
};

int main() {
  int n, q, t, u, v;
  cin >> n >> q;
  UnionFind uf(n);

  for (int i = 0; i < q; ++i) {
    cin >> t >> u >> v;
    if (t == 0) {
      uf.unite(u, v);
    } else if (t == 1) {
      printf("%d\n", uf.is_same(u, v));
    }
  }
}
