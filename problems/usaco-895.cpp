#include <bits/stdc++.h>
using namespace std;

signed main() {

    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);

    int N;
    cin >> N;

    vector<vector<char>> G(N, vector<char>(N));

    for (auto& r : G) {
        for (auto& c : r) {
            cin >> c;
        }
    }

    auto dfs = [&](auto& dfs, int i, int j) -> pair<int, int> {
        if (G[i][j] != '#') return {0, 0};
        G[i][j] = 'v';
        int p = 4;
        int area = 1;
        for (auto [oi, oj] : initializer_list<pair<int, int>>{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}) {
            int ni = i + oi, nj = j + oj;
            if (ni < 0 || ni >= N || nj < 0 || nj >= N) continue;
            auto [add, addarea] = dfs(dfs, ni, nj);
            if (G[ni][nj] == 'v') p--; 
            p += add;
            area += addarea;
        }
        return {p, area};
    };

    int p = INT_MAX, a = 0;
    for (int i = 0; i < N; i++) {
        for (int j  = 0 ; j  < N; j++) {
            auto [np, na] = dfs(dfs, i, j);
            if (na > a) p = np, a = na;
            if (na == a && np < p) p = np;
        }
    }

    cout << a << ' ' << p << endl;
}
