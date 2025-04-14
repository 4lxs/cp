#include <bits/stdc++.h>
using namespace std;

signed main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        int ans = 0;
        if (N % 2 == 1) {
            N -= min(N, K);
            ans++;
        }
        K--;
        int d = N / K;
        ans += d;
        if (d * K != N) ans++;
        cout << ans << endl;
    }
}
