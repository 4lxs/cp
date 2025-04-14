#include <bits/stdc++.h>
using namespace std;

#define int int64_t

const int MOD = 1e9 + 7;

signed main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
    }
    vector<int> a;
    vector<int> num(N, 1);

    vector<bool> vis(N, false);
    a.reserve(N);
    auto topo = [&](auto& topo, int u) -> void {
        if (vis[u]) return;
        vis[u] = true;
        for (int o : G[u]) {
            num[o] = 0;
            if (!vis[o]) topo(topo, o);
        }
        a.push_back(u);
    };

    for (int i = 0; i < N; i++) {
        topo(topo, i);
    }

    reverse(a.begin(), a.end());

    for (int i = 0; i < N - 1; i++) {
        for (int o : G[a[i]]) {
            num[o] += num[a[i]];
            num[o] %= MOD;
        }
    }

    cout << num[a[N - 1]] << endl;
}
