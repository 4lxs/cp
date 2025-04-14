#include <bits/stdc++.h>
using namespace std;

signed main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> F(N);
    vector<vector<int>> Fp(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        F[a].push_back(b);
        Fp[b].push_back(a);
    }

    vector<bool> visited(N);
    auto dfs = [&](auto& dfs, auto& G, int n) {
        if (visited[n]) return;
        visited[n] = true;

        for (int o : G[n]) {
            dfs(dfs, G, o);
        }
    };

    dfs(dfs, F, 0);
    if (auto it = find(visited.begin(), visited.end(), false); it != visited.end()) {
        cout << "NO\n1 " << it - visited.begin() + 1 << endl;
        return 0;
    }
    visited.assign(N, 0);
    dfs(dfs, Fp, 0);

    if (auto it = find(visited.begin(), visited.end(), false); it != visited.end()) {
        cout << "NO\n" << it - visited.begin() + 1 << " 1" << endl;
    }
    else {
        cout << "YES" << endl;
    }
}
