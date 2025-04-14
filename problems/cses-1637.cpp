#include <bits/stdc++.h>
using namespace std;

signed main() {
    int N;
    cin >> N;

    vector<int> memo(N+1, -1);
    memo[0] = 0;

    auto dp = [&](auto&dp, int n) -> int {
        int& ans = memo[n];
        if (ans != -1) return ans;
        int r = n;
        ans = numeric_limits<int>::max();
        for (; r > 0; r /= 10) {
            if (r % 10 == 0) continue;
            ans = min(ans, dp(dp, n - (r % 10)) + 1);
        }
        return ans;
    };

    cout << dp(dp, N) << endl;
}
