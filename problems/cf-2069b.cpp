#include <bits/stdc++.h>
using namespace std;

signed main() {
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;

        vector<vector<int>> G(N, vector<int>(M));
        for (auto& r : G) {
            for (auto& c : r) {
                cin >> c;
            }
        }

        map<int, bool> m;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M ; j++) {
                m.insert({G[i][j], false});
                if (i > 0 && G[i-1][j] == G[i][j]) m[G[i][j]] = true;
                if (j > 0 && G[i][j-1] == G[i][j]) m[G[i][j]] = true;
                if (i < N-1 && G[i+1][j] == G[i][j]) m[G[i][j]] = true;
                if (j < M-1 && G[i][j+1] == G[i][j]) m[G[i][j]] = true;
            }
        }

        int ns = 0, nb = 0;
        for (auto [k, v] : m) {
            if (v) nb++;
            else ns++;
        }

        if (nb == 0) {
            cout << ns - 1 << endl;
        }
        else {
            cout << 2 * (nb - 1) + ns << endl;
        }
    }
}
