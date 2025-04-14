#include <bits/stdc++.h>
using namespace std;

#define int int64_t

#define all(x) x.begin(), x.end()
#define pb push_back
#define sz(x) (int)(x).size()
[[maybe_unused]] const int intmax = std::numeric_limits<int>::max(); // for #define int int64_t
[[maybe_unused]] const int intmin = std::numeric_limits<int>::min(); // for #define int int64_t
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

vi kahn_toposort(vvi& G) {
    int N = G.size();
    vi in_deg(N), ret;
    ret.reserve(N);
    for (auto& i : G) for (auto& i : i) in_deg[i]++;
    queue<int> q;
    for (int i = 0; i < N; i++) if (in_deg[i] == 0) q.push(i);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        ret.push_back(u);
        for (int o : G[u]) {
            if (--in_deg[o] == 0) q.push(o);
        }
    }

    return ret.size() == N ? ret : vi{};
}

void solve() {
    int Na, Nb, Ma, Mb;
    cin >> Na >> Nb >> Ma >> Mb;

    vvi Ga(Na), Gb(Nb);
    vi in_dega(Na), in_degb(Nb);

    for (int i = 0; i < Ma; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        Ga[a].push_back(b);
        in_dega[b]++;
    }

    for (int i = 0; i < Mb; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        Gb[a].push_back(b);
        in_degb[b]++;
    }

    vi tpa = kahn_toposort(Ga), tpb = kahn_toposort(Gb);
    assert(tpa.size() == Na);
    assert(tpb.size() == Nb);

    vector<si> memoa(Na), memob(Nb);

    for (int i = 0; i < Na; i++) {
        if (in_dega[i] == 0) memoa[i] = {0};
    }
    for (int i = 0; i < Nb; i++) {
        if (in_degb[i] == 0) memob[i] = {0};
    }

    for (int i = 0; i < Na; i++) {
        si nw;
        int ci = tpa[i];
        for (auto i : memoa[ci]) nw.insert(i + 1);
        for (auto& o : Ga[ci]) memoa[o].merge(si(nw));
    }

    for (int i = 0; i < Nb; i++) {
        si nw;
        int ci = tpb[i];
        for (auto i : memob[ci]) nw.insert(i + 1);
        for (auto& o : Gb[ci]) memob[o].merge(si(nw));
    }

    bitset<2001> precomp;
    for (int i : memoa.back()) {
        for (int j : memob.back()) {
            if (i + j > 2000) break;
            precomp.set(i + j);
        }
    }

    int Q;
    cin >> Q;

    while (Q--) {
        int q;
        cin >> q;
        cout << (precomp[q] ? "Yes" : "No") << endl;
    }
}
