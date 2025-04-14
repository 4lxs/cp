#include <bits/stdc++.h>
using namespace std;

signed main() {
  freopen("revegetate.in", "r", stdin);
  freopen("revegetate.out", "w", stdout);
  int N, M;
  cin >> N >> M;
  struct Conn {int other; bool same;};
  vector<vector<Conn>> G(N);
  for (int i = 0; i < M; i++) {
    char c;
    int a, b;
    cin >> c >> a >> b;
    a--, b--;
    G[a].push_back({b, c == 'S'});
    G[b].push_back({a, c == 'S'});
  }

  vector<int> color(N, -1);
  auto dfs = [&](auto&&dfs, int me, bool col) -> void {
    if (color[me] != -1 && color[me] != col) {
      cout << 0 << endl;
      exit(0);
    }
    color[me] = col;

    for (auto& o : G[me]) {
      dfs(dfs, o.other, o.same ? col : !col);
    }
  };

  int ans = 0;
  for (int i = 0; i < N; i++) {
    if (color[i] == -1) continue;
    ans++;
    dfs(dfs, i, true);
  }

  printf("1%0*d", ans - 1, 0);
}
