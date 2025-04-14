#include <bits/stdc++.h>
using namespace std;

signed main() {
    int T, N, M;
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> N >> M;
        cout << max(N, M) + 1 << endl;
    }
}
