#include <bits/stdc++.h>
using namespace std;

signed main() {
    int N, X;
    cin >> N >> X;
    vector<int> C(N), P(N);
    for (auto&i : C) cin >> i;
    for (auto&i : P) cin >> i;

    vector<vector<int>> memo(X + 1, vector<int>(N, -1));

    auto dp = [&](auto& dp, int b, int m) -> int {
        if (m == 0) return 0;
        if (b < 0) return 0;

        auto& ans = memo[m][b];
        if (ans != -1) return ans;
        if (m >= C[b]) ans = dp(dp, b - 1, m - C[b]) + P[b];
        return ans = max(dp(dp, b - 1, m), ans);
    };

    cout << dp(dp, N - 1, X) << endl;
}
