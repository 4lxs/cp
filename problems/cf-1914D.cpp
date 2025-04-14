#include <bits/stdc++.h>
using namespace std;

#define int int64_t

#define all(x) begin(x), end(x)
#define pb push_back
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define lsone(x) ((x) & -(x)) // least significant one (01010 -> 00010)
[[maybe_unused]] const int inf = std::numeric_limits<int>::max(); // for #define int int64_t
[[maybe_unused]] const int minf = std::numeric_limits<int>::min(); // for #define int int64_t
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

#define testcases rdi(tc); for (int t = 1; t <= tc; t++)

void setIO(string name = "") {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  if (!name.empty()) {
#ifndef LOCAL
    (void)freopen((name + ".in").c_str(), "r", stdin);
    (void)freopen((name + ".out").c_str(), "w", stdout);
#endif
  }
}

array<pii, 3> topd(vi a) {
    array<pii, 3> out = {pii{a[0], 0}, {a[1], 1}, {a[2], 2}};
    sort(all(out));
    for (int i = 3; i < a.size(); i++) if (a[i] > out[0].first) out[0] = {a[i], i}, sort(all(out));
    return out;
}

signed main() {
  setIO("");

  testcases {
      rdi(N);
      rdvin(A, N);
      rdvin(B, N);
      rdvin(C, N);

      set<int> days;
      for (auto &i : {A, B, C}) {
          auto a = topd(i);
          dbg(i, a);
          days.insert(a[0].second);
          days.insert(a[1].second);
          days.insert(a[2].second);
      }
      vector<int> d(all(days));
      dbg(d);
      int out = 0;
      for (int i = 0; i < sz(d); i++)
          for (int j = i + 1; j < sz(d); j++)
              for (int k = j + 1; k < sz(d); k++) {
                  out = max({out, A[d[i]] + B[d[j]] + C[d[k]], A[d[i]] + C[d[j]] + B[d[k]], B[d[i]] + A[d[j]] + C[d[k]], B[d[i]] + C[d[j]] + A[d[k]], C[d[i]] + A[d[j]] + B[d[k]], C[d[i]] + B[d[j]] + A[d[k]]});
              }

      cout << out << endl;
  }
}
