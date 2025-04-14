#include <bits/stdc++.h>
using namespace std;

signed main() {
    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);
    int N, M;
    cin >> N >> M;

    vector<tuple<int, int, vector<int>>> C(N);

    for (auto& [x, y, n] : C) {
        cin >> x >> y;
    }

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;

        get<2>(C[a]).push_back(b);
        get<2>(C[b]).push_back(a);
    }

    vector<bool> visited(N);
    int minx = numeric_limits<int>::max(), miny = numeric_limits<int>::max(), maxx = numeric_limits<int>::min(), maxy = numeric_limits<int>::min();
    auto dfs = [&](auto dfs, int n) {
        if (visited[n]) return;
        visited[n] = true;
        auto& [x, y, _] = C[n];
        minx = min(x, minx), maxx = max(x, maxx), miny = min(y, miny), maxy = max(maxy, y);

        for (int o : get<2>(C[n])) {
            dfs(dfs, o);
        }
    };

    int ans = numeric_limits<int>::max();
    for (int i = 0; i < N; i++) {
        if (visited[i]) continue;
        minx = numeric_limits<int>::max(), miny = numeric_limits<int>::max(), maxx = numeric_limits<int>::min(), maxy = numeric_limits<int>::min();
        dfs(dfs, i);
        ans = min(ans, abs(minx - maxx) * 2 + abs(miny - maxy) * 2);
    }

    cout << ans << endl;
}
