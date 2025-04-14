#include <bits/stdc++.h>
using namespace std;
#define int int64_t

signed main() {
  int n, y, x;
  cin >> n >> x >> y;

  int out = 0;
  while (n) {
    if (n % 2 == 1) {
      n--;
      out += x;
    }

    if (y > x * (n / 2)) {
      out += x * n;
      break;
    }

    n /= 2;
    out += y;
  }

  cout << out << endl;
}
