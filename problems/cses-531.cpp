
#include <bits/stdc++.h>
#include <queue>
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
  setIO("superbull");
  int tc = 1;
  // cin >> tc;
  for (int t = 1; t <= tc; t++) {
    dbg("Case #", t, ":");
    solve();
  }
}

int mst_prim(vvpii& G) {
    int N = G.size();
    priority_queue<pii> pq;
    pq.push({0, 0});
    vi dist(N, minf);
    dist[0] = 0;
    vb vis(N);
    int min_cost = 0, added = 0;

    while (added < N) {
        if (pq.empty()) return -1;
        auto [w, u] = pq.top(); pq.pop();
        if (dist[u] > w) continue;
        dbg(u, w);
        vis[u] = true;
        added++;
        min_cost += w;
        for (auto [o, w] : G[u]) {
            if (vis[o] || dist[o] > w) continue;
            dist[o] = w;
            pq.push({w, o});
        }
    }

    return min_cost;
}

void solve() {
    rdi(N);
    rdvin(A, N);

    vvpii G(N);
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int w = A[i] ^ A[j];
            G[i].push_back({j, w});
            G[j].push_back({i, w});
        }
    }
    dbg(G);
    cout << mst_prim(G) << endl;
}
