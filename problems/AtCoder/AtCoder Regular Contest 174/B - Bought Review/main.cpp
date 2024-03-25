///
/// name: B - Bought Review
/// link: https://atcoder.jp/contests/arc174/tasks/arc174_b
/// start: Sun Mar 17 13:39:34 2024
///

#include <bits/stdc++.h>
using namespace std;

#define int int64_t

#define all(x) x.begin(), x.end()
#define pb push_back
#define sz(x) (int)(x).size()
[[maybe_unused]] const int intmax = std::numeric_limits<int>::max(); // for #define int int64_t
[[maybe_unused]] const int intmin = std::numeric_limits<int>::min(); // for #define int int64_t
[[maybe_unused]] const int mod = 10e9 + 7;
using vi = vector<int>;
using vvi = vector<vi>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using si = set<int>;
using pii = pair<int, int>;
using vpii = vector<pii>;
using vvpii = vector<vpii>;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

template<typename... Args> void __read(Args&&... args) { (cin >> ... >> args); }
#define rdi(...) int __VA_ARGS__; __read(__VA_ARGS__)
#define rdc(...) char __VA_ARGS__; __read(__VA_ARGS__)
#define rds(...) string __VA_ARGS__; __read(__VA_ARGS__)
#define rdvin(var, n) vi var(n); for (auto & i : var) cin >> i;
#define rdvbn(var, n) vb var(n); for (auto & i : var) cin >> i;
#define rdvcn(var, n) vc var(n); for (auto & i : var) cin >> i;

void setIO(string name = "") {
  cin.tie(0)->sync_with_stdio(0);
  if (!name.empty()) {
#ifndef LOCAL
    (void)freopen((name + ".in").c_str(), "r", stdin);
    (void)freopen((name + ".out").c_str(), "w", stdout);
#endif
  }
}

void solve();

signed main() {
  setIO("");
  int tc = 1;
  cin >> tc;
  for (int t = 1; t <= tc; t++) {
    dbg("Case #", t, ":");
    solve();
  }
}


void solve() {
  rdvin(counts, 5);
  rdvin(prices, 5);
  int sum = 2 * counts[0] + counts[1] - counts[3] - 2 * counts[4];
  if (sum <= 0) {
    cout << 0 << endl;
    return;
  }

  bool buy5s = prices[4] > 2 * prices[3];

  int cnt5s = 0, cnt4s = 0;
  if (buy5s) {
    cnt5s = sum / 2;
    cnt5s += sum % 2;
  } else {
    cnt4s = sum;
  }

  int price = prices[4] * cnt5s + prices[3] * cnt4s;
  if (cnt5s > 0) {
    int newprice = prices[4] * (cnt5s-1) + prices[3] * (cnt4s+1);
    if (newprice < price && cnt5s * 2 + cnt4s >= sum) {
      cnt5s--;
      cnt4s++;
    }
  }

  dbg(cnt4s, cnt5s);
  price = prices[4] * cnt5s + prices[3] * cnt4s;
  cout << price << endl;
}
