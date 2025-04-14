#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;

signed main() {
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
    int N , Q;
    cin >> N >> Q;

    vector<vector<pii>> G(N + 1);

    for (int i = 0; i < N - 1; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        G[a].push_back({b, w});
        G[b].push_back({a, w});
    }

    while (Q--) {
        int k, v, ans = 0;
        cin >> k >> v;
        cerr << k << "  " << v << endl;

        auto dfs = [&](auto& dfs, int n, int p) -> void {
            ans++;
            for (auto [o, w] : G[n]) {
                if (k > w || o == p) continue;

                dfs(dfs, o, n);
            }
        };

        dfs(dfs, v, v);
        cout << ans - 1 << endl;
    }
}
