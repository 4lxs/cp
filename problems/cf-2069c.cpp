#include <bits/stdc++.h>
using namespace std;

#define int int64_t

int mod = 998244353;

signed main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<pair<int, int>> ones;
        int twos = 0;
        int ans = 0;
        int nt = 0, tw = 0;
        vector<int> A(N);
        for (auto& i : A) cin >> i;
        for(int i = 0; i < N; i++) {
            int a = A[i];

            if (a == 1) {
                if (ones.size() && ones.back().first == twos) ones.back().second++;
                else {
                    ones.push_back({twos, 1});
                }
            }
            else if (a == 2) {
                twos++;
            }
            else {
                nt++;
                if (i < N - 1 && A[i+1] == 3) {
                    continue;
                }
                for (auto [ot, no] : ones) {
                    int add = 1;
                    int nmul = twos - ot;
                    while (nmul > 0) {
                        add = (add << min(nmul, int64_t(32))) % mod;
                        nmul -= 32;
                    }
                    add--;
                    ans += (((add * no) % mod) * nt) % mod;
                    ans %= mod;
                }
                nt = 0;
            }
        }

        cout << ans << endl;
    }
}
