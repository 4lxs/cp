///
/// name: D. Rudolf and the Ball Game
/// link: https://codeforces.com/contest/1941/problem/D
/// start: Mon Mar 11 16:13:41 2024
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
  cin >> tc;
  for (int t = 1; t <= tc; t++) {
    dbg("Case #", t, ":");
    solve();
  }
}


void solve() {
  rdi(np, nt, p1);
  vi throws(nt);
  vc throwdir(nt);
  for (int i = 0; i < nt; i++) {
    cin >> throws[i] >> throwdir[i];
  }
  vb canreach(np, false), nextturn(np, false);
  canreach[p1-1] = true;

  for (int i = 0; i < nt; i++) {
    dbg(i);
    for (int p = 0; p < np; p++) {
      if (canreach[p]) {
        if (throwdir[i] == '0' || throwdir[i] == '?') {
          dbg((p + throws[i]) % np);
          nextturn[(p + throws[i]) % np] = true;
        }
        if (throwdir[i] == '1' || throwdir[i] == '?') {
          dbg((p - throws[i] + np) % np);
          nextturn[(p - throws[i] + np) % np] = true;
        }
      }
    }
    canreach = nextturn;
    nextturn.assign(np, false);
  }

  cout << count(all(canreach), true) << endl;
  for (int p = 0; p < np; p++) {
    if (canreach[p]) {
      cout << p+1 << ' ';
    }
  }
  cout << endl;
}
