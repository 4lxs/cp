#include <bits/stdc++.h>
using namespace std;

#define int int64_t
const int MOD = 10e9 + 7;

signed main() {
    int N, X;
    cin >> N >> X;

    vector<int> A(N);
    for (auto&i : A) cin >> i;

    vector<vector<int>> memo(X + 1, vector<int>(N, -1));

    auto dp = [&](auto& dp, int c, int s) -> int {
        if (s == 0) return 1;
        if (s < 0) return 0;
        if (c < 0) return 0;
        auto& ans = memo[s][c];
        if (ans != -1) return ans;

        ans = 0;
        if (s >= A[c]) ans += dp(dp, c, s - A[c]);
        ans += dp(dp, c-1, s);
        return ans %= MOD;
    };

    cout << dp(dp, N-1, X) << endl;
}
