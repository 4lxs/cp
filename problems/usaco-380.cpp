#include <bits/stdc++.h>
using namespace std;

signed main() {
    freopen("ccski.in", "r", stdin);
    freopen("ccski.out", "w", stdout);
    int M, N;
    cin >> M >> N;
    vector<vector<int>> G(M, vector<int>(N)), W(M, vector<int>(N));
    for (auto& i : G) for (auto& j : i) cin >> j;

    int wi, wj, nw = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> W[i][j];
            if (W[i][j]) {
                wi = i, wj = j, nw++;
            }
        }
    }

    priority_queue<tuple<int, int, int>> pq;
    pq.push({0, wi, wj});
    int maxd = 0;

    while (!pq.empty()) {
        auto [d, i, j] = pq.top(); pq.pop();
        d = -d;
        if (W[i][j] == -1) continue;
        // fprintf(stderr, "%d %d %d\n", d, i , j);
        maxd = max(d, maxd);
        if (W[i][j]) nw--;
        if (nw == 0) break;
        W[i][j] = -1;
        for (auto& [di, dj] : {pair<int, int>{1, 0}, {-1, 0}, {0, 1}, {0, -1}}) {
            int ni = i + di;
            int nj = j + dj;
            if (ni < 0 || ni == M) continue;
            if (nj < 0 || nj == N) continue;
            if (W[ni][nj] == -1) continue;
            pq.push({-abs(G[i][j] - G[ni][nj]), ni, nj});
        }
    }

    cout << maxd << endl;
}
