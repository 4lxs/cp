#include <bits/stdc++.h>
using namespace std;

#define int int64_t

#define all(x) x.begin(), x.end()
#define pb push_back
#define sz(x) (int)(x).size()
[[maybe_unused]] const int inf = std::numeric_limits<int>::max(); // for #define int int64_t
[[maybe_unused]] const int minf = std::numeric_limits<int>::min(); // for #define int int64_t
[[maybe_unused]] const int mod = 1e9 + 7;
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

vi dijkstra(vvpii& G, int s, int e) {
  int N = G.size();
  vi dist(N, inf);
  dist[s] = 0;

  priority_queue<pii, vector<pii>, greater<pii>> pq;
  pq.push({0, s});

  while (!pq.empty()) {
    auto [d, u] = pq.top(); pq.pop();
    if (dist[u] < d) continue;
    for (auto [o, w] : G[u]) {
      if (dist[u] + w < dist[o]) {
        pq.push({dist[o] = dist[u] + w, o});
      }
    }
  }

  return dist;
}

void solve() {
  int N, M;
  cin >> N >> M;

  vvpii G(N + 1), rG(N + 1);
  for (int i = 0; i < M; i++) {
    rdi(a, b, c);
    G[a].push_back({b, c});
    rG[b].push_back({a, c});
  }

  vi dist0 = dijkstra(G, 1, -1), distN = dijkstra(rG, N, -1);

  int ans = inf;
  for (int u = 1; u <= N; u++) {
    for (auto [o, w] : G[u]) {
      if (dist0[u] == inf || distN[o] == inf) continue;
      ans = min(ans, dist0[u] + w / 2 + distN[o]);
    }
  }

  cout << ans << endl;
}
