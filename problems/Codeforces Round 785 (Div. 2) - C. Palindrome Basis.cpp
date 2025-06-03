#define testcases

#include <bits/stdc++.h>
using namespace std;

#define int int64_t
const string name = ""; // for usaco

#define all(x) begin(x), end(x)
#define pb push_back
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define lsone(x) ((x) & -(x)) // least significant one (01010 -> 00010)
#define nl '\n'
#define endl
[[maybe_unused]] const int inf =
    std::numeric_limits<int>::max(); // for #define int int64_t
[[maybe_unused]] const int minf =
    std::numeric_limits<int>::min(); // for #define int int64_t
[[maybe_unused]] const int mod = 1e9 + 7;
typedef long long ll;
using vi = vector<int>;
using vvi = vector<vi>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using si = set<int>;
using pii = pair<int, int>;
using vpii = vector<pii>;
using vvpii = vector<vpii>;
using vs = vector<string>;
using vvs = vector<vs>;
using vc = vector<char>;
using vvc = vector<vc>;

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
  return os << '(' << p.first << ", " << p.second << ')';
}
template <typename T_container, typename T = typename enable_if<
                                    !is_same<T_container, string>::value,
                                    typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v) {
  os << '{';
  string sep;
  for (const T &x : v)
    os << sep << x, sep = ", ";
  return os << '}';
}
void dbg_out() { cerr << nl; }
template <typename Head, typename... Tail> void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

template <typename... Args> void __read(Args &&...args) {
  (cin >> ... >> args);
}
#define rdi(...)                                                               \
  int __VA_ARGS__;                                                             \
  __read(__VA_ARGS__)
#define rdc(...)                                                               \
  char __VA_ARGS__;                                                            \
  __read(__VA_ARGS__)
#define rds(...)                                                               \
  string __VA_ARGS__;                                                          \
  __read(__VA_ARGS__)
#define rdvin(var, n)                                                          \
  vi var(n);                                                                   \
  for (auto &i : var)                                                          \
    cin >> i;
#define rdvbn(var, n)                                                          \
  vb var(n);                                                                   \
  for (auto &i : var)                                                          \
    cin >> i;
#define rdvcn(var, n)                                                          \
  vc var(n);                                                                   \
  for (auto &i : var)                                                          \
    cin >> i;

void solve();
void init();

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  init();
  if (!name.empty()) {
#ifndef LOCAL
    (void)freopen((name + ".in").c_str(), "r", stdin);
    (void)freopen((name + ".out").c_str(), "w", stdout);
#endif
  }
  int tc = 1;
#ifdef testcases
  cin >> tc;
#endif
  for (int t = 1; t <= tc; t++) {
    dbg("Case #", t, ":");
    solve();
  }
}

vi palindromes;

void init() {
  palindromes.reserve(10000);
  for (int i = 0; i <= 9; i++)
    palindromes.pb(i);
  for (int i = 0; i <= 9; i++)
    for (int j = 1; j < 10; j++)
      palindromes.pb(100 * j + 10 * i + j);
  for (int a = 0; a <= 9; a++)
    for (int j = 1; j < 10; j++)
      palindromes.pb(1000 * j + 100 * a + 10 * a + j);
  for (int a = 0; a <= 9; a++)
    for (int b = 0; b <= 9; b++)
      for (int j = 1; j < 6; j++)
        palindromes.pb(10000 * j + 1000 * a + 100 * b + 10 * a + j);
}

void solve() {
  rdi(N);

  auto dp = [&](auto &dp, int k, int p) -> int {
    if (k == 0)
      return 1;
    if (p < 0)
      return 0;
    int ans = 0;
    if (k > palindromes[p]) {
      ans += dp(dp, k - palindromes[p], p);
    }
    ans += dp(dp, k, p - 1);
    return ans;
  };

  rep(n, 0, N) {
    rdi(k);
    cout << dp(dp, k, palindromes.size() - 1) << nl;
  }
}
