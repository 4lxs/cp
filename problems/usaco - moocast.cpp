#include <bits/stdc++.h>
using namespace std;

signed main() {
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    int n;
    cin >> n;

    vector<tuple<int, int, int>> cows(n);
    for (auto& [x, y, r] : cows) {
        cin >> x >> y >> r;
    }

    vector<vector<int>> G(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            auto& [jx, jy, jr] = cows[j];
            auto& [ix, iy, ir] = cows[i];
            double dist = sqrt(pow(abs(ix - jx), 2) + pow(abs(iy - jy), 2));
            if (ir >= dist) G[i].push_back(j);
            if (jr >= dist) G[j].push_back(i);
        }
    }

    vector<int> visited(n);
    auto dfs = [&](auto& dfs, int n) {
        if (visited[n]) return;
        visited[n] = 1;

        for (int o : G[n]) dfs(dfs, o);
    };

    int out = 0;
    for (int i = 0; i < n; i++) {
        visited.assign(n, 0);

        dfs(dfs, i);
        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                cerr << i << " ";
            }
        }
        cerr << i << " " << count(visited.begin(), visited.end(), 1) << endl;
        out = max(int(count(visited.begin(), visited.end(), 1)), out);
    }
    cout << out << endl;
}
