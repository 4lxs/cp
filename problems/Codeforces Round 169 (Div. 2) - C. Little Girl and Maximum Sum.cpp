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

/**
 * Author: Lukas Polacek
 * Date: 2009-10-30
 * License: CC0
 * Source: folklore/TopCoder
 * Description: Computes partial sums a[0] + a[1] + ... + a[pos - 1], and
 * updates single elements a[i], taking the difference between the old and new
 * value. Time: Both operations are $O(\log N)$. Status: Stress-tested
 */
#pragma once

struct FT {
  vector<ll> s;
  FT(int n) : s(n) {}
  void update(int pos, ll dif) { // a[pos] += dif
    for (; pos < sz(s); pos |= pos + 1)
      s[pos] += dif;
  }
  ll query(int pos) { // sum of values in [0, pos)
    ll res = 0;
    for (; pos > 0; pos &= pos - 1)
      res += s[pos - 1];
    return res;
  }
  int lower_bound(ll sum) { // min pos st sum of [0, pos] >= sum
    // Returns n if no sum is >= sum, or -1 if empty sum is.
    if (sum <= 0)
      return -1;
    int pos = 0;
    for (int pw = 1 << 25; pw; pw >>= 1) {
      if (pos + pw <= sz(s) && s[pos + pw - 1] < sum)
        pos += pw, sum -= s[pos - 1];
    }
    return pos;
  }
};

void solve() {
  rdi(N, Q);

  rdvin(a, N);

  FT ft(N + 2);

  rep(i, 0, Q) {
    rdi(l, r);
    ft.update(l, 1);
    ft.update(r + 1, -1);
  }

  vi cnts;
  rep(i, 2, N + 2) { cnts.pb(ft.query(i)); }
  dbg(a, cnts);

  sort(all(a));
  sort(all(cnts));
  int ans = 0;
  rep(i, 0, N) { ans += cnts[i] * a[i]; }

  cout << ans << nl;
}
