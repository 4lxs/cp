#include <bits/stdc++.h>
using namespace std;

int f(int x) {
    return x == 0 ? 0 : :x

}

signed main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int c = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '1') continue;
            c++;
            while (s[i] == '1') i++;
        }

        cout << f(c) << endl;
    }
}
