#include <bits/stdc++.h>
using namespace std;

#define int int64_t

const int mod = 998244353;

signed main() {
    int Q, K;
    cin >> Q >> K;

    vector<int> memo(K+1, 0);
    memo[0] = 1;

    while (Q--) {
        char S;
        int R;
        cin >> S >> R;

        if (S == '+') {
            for (int i = K; i - R >= 0; i--) {
                memo[i] += memo[i - R];
                memo[i] %= mod;
            }
        } else {
            for (int i = R; i <= K; i++) {
                memo[i] += mod - memo[i - R];
                memo[i] %= mod;
            } 
        }
        
        // for (int i : memo) {
        //     cerr << i << ' ';
        // }
        // cerr << endl;
        cout << memo[K] << endl;
    }
}
