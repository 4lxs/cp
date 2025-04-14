#include <bits/stdc++.h>
using namespace std;
#define int int64_t

signed main() {
    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;

        vector<int> R(N), D(M);
        for (auto& i : R) cin >> i;
        for (auto& i : D) cin >> i;

        int mr = R[0];
        sort(R.begin(), R.end());
        R = vector<int>(upper_bound(R.begin(), R.end(), mr), R.end());
        vector<int> G(M);
        for (int i = 0; i < M; i++) {
            if (D[i] <= mr) {
                G[i] = 1;
            } else {
                G[i] = 1 + R.size() - (lower_bound(R.begin(), R.end(), D[i]) - R.begin());
            }
            // cerr << G[i] << ' ';
        }
        // cerr << endl;

        sort(G.begin(), G.end());
        for (int m = 1; m <= M; m++) {
            int sum = 0;
            for (int i = m - 1; i < M; i += m) {
                sum += G[i];
            }
            cout << sum << ' ';
        }
    }
}
