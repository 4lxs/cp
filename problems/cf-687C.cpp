#include <bits/stdc++.h>
using namespace std;

signed main() {
    int N, K;
    cin >> N >> K;

    vector<int> C(N);
    for (auto&i : C) cin >> i;

    vector<vector<vector<bool>>> memo(N, vector<vector<bool>>(K + 1, vector<bool>(K + 1)));
    memo[0][0][0] = true;
    bitset<501> ans(false);
    ans[0] = true;

    for (int c = 0; c < N; c++) {
        for (int sum = 0; sum < K; sum++) {
            for (int ss = 0; ss < K; ss++) {
                if (!memo[c][sum][ss]) continue;
                // cerr << c << " " << sum << " " << ss << endl;
                if (c == N - 1) {
                    if (sum + C[c] <= K) {
                        // cerr << ss + C[c] << endl;
                        ans[ss + C[c]] = true;
                    }
                    continue;
                }

                if (sum + C[c] <= K) {
                    memo[c + 1][sum + C[c]][ss] = true;
                    memo[c + 1][sum + C[c]][ss + C[c]] = true;
                    ans[ss + C[c]] = true;
                }
                memo[c + 1][sum][ss] = true;
            }
        }
    }

    cout << ans.count() << endl;
    for (int i = 0; i < ans.size(); i++) {
        if (ans[i]) cout << i << ' ';
    }
    cout << endl;
}
