#include <bits/stdc++.h>
using namespace std;

#define int int64_t
const int MOD = 1e9 + 7;

signed main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for (auto&i : A) cin >> i;

    vector<vector<int>> g(N, vector<int>(M + 2, 0));
    
    for (int i = 1; i <= M; i++) {
        g[0][i] = A[0] == 0 || A[0] == i ? 1 : 0;
    }

    for (int n = 1; n < N; n++) {
        for (int m = 1; m <= M; m++) {
            if (A[n] != 0 && A[n] != m) continue;

            g[n][m] = g[n - 1][m - 1] + g[n - 1][m] + g[n - 1][m + 1];
            g[n][m] %= MOD;
        }
    }

    int ans = 0;
    for (int i = 1; i <= M; i++) {
        ans += g[N - 1][i];
        ans %= MOD;
    }

    cout << ans << endl;
}
