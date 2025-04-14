#include <bits/stdc++.h>
using namespace std;

signed main() {
    int T, N, K;
    cin >> T;
    while (T--) {
        cin >> N >> K;
        vector<int> count, A(N);
        for (int& i : A) cin >> i;

        sort(A.begin(), A.end());
        for (int i = 0; i < N; i++) {
            int cnt = 1;
            while (i + 1 < N && A[i] == A[i+1]) {
                i++, cnt++;
            }
            count.push_back(cnt);
        }
        sort(count.begin(), count.end());
        int ans = count.size();
        // cerr << ans << endl;
        for (int i : count) {
            if (K >= i) {
                ans--;
                K -= i;
            } else break;
        }
        cout << max(ans, 1) << endl;
    }
}
