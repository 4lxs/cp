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
  init();
  for (int t = 1; t <= tc; t++) {
    dbg("Case #", t, ":");
    solve();
  }
}

void init() {}

void solve() {
  rdi(N);

  rdvin(a, N);

  if (count(all(a), 0) == N) {
    cout << "NO" << nl;
    return;
  }

  vi pos, neg;
  int mp = 0, mn = 0;

  cout << "YES" << nl;

  for (int i : a) {
    mp = max(mp, i);
    mn = min(mn, i);
    if (i == 0)
      cout << i << " ";
    else if (i > 0)
      pos.pb(i);
    else
      neg.pb(i);
  }

  int b = mp - mn;
  int rs = 0;
  while (!neg.empty() || !pos.empty()) {
    if (rs > 0) {
      cout << neg.back() << " ";
      rs += neg.back();
      neg.pop_back();
    } else {
      cout << pos.back() << " ";
      rs += pos.back();
      pos.pop_back();
    }
  }
  cout << nl;
}
