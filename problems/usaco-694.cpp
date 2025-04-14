#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int memo[3][21][100000] {};

signed main() {
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);

    int N, K;
    cin >> N >> K;
    vector<char> A(N);
    for (char&i : A) cin >> i;

    char mp[] = {'H', 'P', 'S'};

    for (int n = N-1; n >= 0; n--) {
        // fprintf(stderr, "vs %c\n", A[n]);
        for (char tt : {0, 1, 2}) {
            for (int k = 0; k <= K; k++) {
                char j = A[n];
                bool won = false;
                int t = mp[tt];
                won |= t == 'H' && j == 'S';
                won |= t == 'P' && j == 'H';
                won |= t == 'S' && j == 'P';
                memo[tt][k][n] = won ? 1 : 0;
                if (n + 1 < N) {
                    if (k == 0) {
                        memo[tt][k][n] += memo[tt][k][n + 1];
                        // fprintf(stderr, "%c %d %d = %d\n", t, k, n, memo[tt][k][n]);
                        continue;
                    }
                    int sh = memo[0][k - (t != 'H')][n + 1];
                    int sp = memo[1][k - (t != 'P')][n + 1];
                    int ss = memo[2][k - (t != 'S')][n + 1];
                    memo[tt][k][n] += max({sh, sp, ss});
                }
                // fprintf(stderr, "%c %d %d = %d\n", t, k, n, memo[tt][k][n]);
            }
        }
    }

    cout << max({memo[0][K][0], memo[1][K][0], memo[2][K][0]}) << endl;
}
