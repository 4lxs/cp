// #define testcases

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
  for (int t = 1; t <= tc; t++) {
    dbg("Case #", t, ":");
    solve();
  }
}

void solve() {
  rdi(N);
  rdvcn(a, N);
  rdi(Q);
  int cp = 0, cm = 0;
  for (char c : a)
    if (c == '+')
      cp++;
    else
      cm++;

  int cd = abs(cm - cp), csml = min(cp, cm);

  rep(q, 0, Q) {
    rdi(l, r);
    dbg(l, r);
    if (l == r) {
      cout << (cd == 0 ? "YES" : "NO") << nl;
      continue;
    }
    int cm = lcm(l, r);
    l = cm / l;
    r = cm / r;
    int dd = abs(l - r);

    if (dd == 0) {
      cout << (cd % 2 == 0 ? "YES" : "NO") << nl;
      continue;
    }
    dbg(cd, dd, cm, csml);
    int cdd = cd / dd;
    cout << ((cd % dd) == 0 && cdd <= csml && csml - cdd * min(l, r) >= 0
                 ? "YES"
                 : "NO")
         << nl;
  }
}
