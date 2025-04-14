#include <bits/stdc++.h>
using namespace std;

signed main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N-2);
        for (auto& i : A) cin >> i;
        for (int i = 1; i < N-3; i++) {
            if (A[i-1] == 1 && A[i] == 0 && A[i+1] == 1) {
                cout << "NO" << endl;
                goto end;
            }
        }
        cout << "YES" << endl;
        continue;
end:;
    }
}
