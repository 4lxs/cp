#include <bits/stdc++.h>
using namespace std;

#define int int64_t

bool is_sq[1000010] = {false};

signed main() {
    int ns = 1, s = 1;
    for (int i = 1; i < 1000010; i++) {
        int sum = (i * (i + 1)) / 2;
        while (sum > ns) s++, ns = s * s;
        if (ns == sum) {
            is_sq[i] = true;
        
    }
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        if (is_sq[N]) {
            cout << -1 << endl;
            continue;
        }

        for (int i = 1; i <= N; i++) {
            if (is_sq[i]) {
                cout << i + 1 << " " << i << " ";
                i++;
            }
            else {
                cout << i << " ";
            }
        }
        cout << endl;
    }
}
