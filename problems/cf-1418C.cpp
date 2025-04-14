#include <bits/stdc++.h>
using namespace std;

signed main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int&i : A) cin >> i;

        vector<vector<int>> memo(2, vector<int>(N, -1));

        auto dp = [&](auto& dp, int turn, int m) -> int {
            if (m >= N) return 0;
            int& ans = memo[turn][m];
            if (ans != -1) return ans;

            if (m == N - 1) return A[m] * turn;
            return ans = min(A[m] * turn + dp(dp, !turn, m + 1), (A[m] + A[m + 1]) * turn + dp(dp, !turn, m + 2));
        };

        cout << dp(dp, 1, 0) << endl;
    }
}
