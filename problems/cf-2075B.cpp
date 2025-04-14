#include <bits/stdc++.h>
using namespace std;

signed main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<pair<int, int>> A(N);
        for (int i = 0; i < N; i++) cin >> A[i].first, A[i].second = i;
        sort(A.begin(), A.end());
        int ans = 0;
        int l = A[N - 1].second, r = A[N - 2].second;
        if (K == 1 && N > 3 && ((l == 0 && r == 1) || (r == N - 2 && l == N - 1))) {
            cout << (A[N - 1].first + A[N - 3].first) << endl;
            continue;
        }
        for (int i = 0; i <= K; i++) {
            ans += A[N - i - 1].first;
        }
        cout << ans << endl;
    }
}
