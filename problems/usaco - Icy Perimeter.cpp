// https://usaco.org/index.php?page=viewproblem2&cpid=895
#include <bits/stdc++.h>
#include <initializer_list>
using namespace std;

signed main() {
  int N;
  cin >> N;

  vector<vector<char>> G(N, vector<char>(N));
  for (auto& i : G) {
    for (auto& i : i) {
      cin >> i;
    }
  }

  int ansa = 0, ansp;
  vector<pair<int, int>> q;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (G[i][j] != '#') continue;
      int a = 0, p = 0, pa = 0;
      q.push_back({i, j});
      while (!q.empty()) {
        auto [x, y] = q.back();
        q.pop_back();
        a++;
        p += 4;

        for (auto [xo, yo] : initializer_list<pair<int, int>>{{0, -1}, {0, 1}, {-1, 0}, {1, 0}}) {
          if (!(x + xo < N && x + xo >= 0 && y + yo < N && y + yo >= 0)) continue;
          if (G[x + xo][y + yo] == 'v') {
            pa++;
          }
          if (G[x + xo][y + yo] == '#') {
            pa++;
            G[x + xo][y + yo] = 'v';
            q.push_back({x + xo, y  + yo});
          }
        }
      }
      p += pa / 2;
      if (ansa < a || (ansa == a && p < ansp)) {
        ansa = a;
        ansp = p;
      }
    }
  }

  cout << ansa << ' ' << ansp << endl;
}
