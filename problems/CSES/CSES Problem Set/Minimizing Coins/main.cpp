///
/// name: Minimizing Coins
/// link: https://cses.fi/problemset/task/1634
/// start: Sun Mar  3 11:35:00 2024
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
using vvi = vector<vector<int>>;
using vb = vector<bool>;
using vc = vector<char>;
using si = set<int>;
using pii = pair<int, int>;
using vpii = vector<pii>;
using vvpii = vector<vector<pii>>;

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
#define rdvin(var, n) vi var(n); for (auto & i : var) cin >> i;
#define rdvbn(var, n) vb var(n); for (auto & i : var) cin >> i;
#define rdvcn(var, n) vc var(n); for (auto & i : var) cin >> i;
#define rds(var) string var; cin >> var;

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
  // cin >> tc;
  for (int t = 1; t <= tc; t++) {
    dbg("Case #", t, ":");
    solve();
  }
}

int calc2(int used, int need, int ncoins, vvi & memo, vi & coins) {
  // dbg(used, need);
  if (need < 0) return -1;
  if (need == 0) return 0;
  if (used == ncoins) return -1;
  if (memo[used][need] != -2) return memo[used][need];

  int out = -1;
  int tmp = calc2( used, need - coins[used], ncoins, memo, coins);
  int tmp2 = calc2( used + 1, need, ncoins, memo, coins);
  if (tmp != -1 && tmp2 != -1) out = min(1 + tmp, tmp2);
  else if (tmp != -1) out = tmp + 1;
  else if (tmp2 != -1) out = tmp2;
  // dbg(used, need, out);
  return memo[used][need] = out;
}

void solve() {
  rdi(ncoins, neededsum);
  rdvin(coins, ncoins);

  vi memo(neededsum + 1);
  memo[0] = 0;
  for (int i = 1; i <= neededsum; i++) {
    int nmin = intmax - 1;
    for (auto coin : coins) {
      if (i - coin < 0) continue;
      nmin = min(nmin, 1 + memo[i-coin]);
    }
    memo[i] = nmin;
    // dbg(i, memo[i]);
  }

  cout << (memo[neededsum] == intmax - 1 ? -1 : memo[neededsum]) << endl;
}
