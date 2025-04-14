#include <bits/stdc++.h>
using namespace std;
#define int int64_t

struct bit {
    vector<int> a, arr;
    bit(int n) : a(n+1), arr(n) {}

    int sum(int k) {
        int s = 0;
        for (k++; k; k -= k&-k) s += a[k];
        return s;
    }

    void add(int k, int v) {
        arr[k] += v;
        for (k++; k < a.size(); k += k&-k) a[k] += v;
    }

    int sum(int a, int b) {
        if (a == 0) return sum(b);
        return sum(b) - sum(a-1);
    }

    void set(int k, int v) {
        add(k, v - arr[k]);
    }
};

pair<vector<int>, vector<int>> tour(vector<vector<int>> adj) {
    int t = 0;
    vector<int> a(adj.size()), e(adj.size());

    auto tour = [&](auto& tour, int i, int p) -> void {
        a[i] = t++;
        for (auto s : adj[i]) {
            if (s != p) tour(tour, s, i);
        }

        e[i] = t;
    };

    tour(tour, 0, 0);

    return {a, e};
};


signed main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> V(N);
    for (auto&i : V) cin >> i;

    vector<vector<int>> G(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    auto [a, e] = tour(G);

    bit b(N);

    for (int i = 0; i < N; i++) {
        b.add(a[i], V[i]);
    }

    while (Q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int s, x;
            cin >> s >> x;
            b.set(a[s-1], x);
        }
        else {
            int s;
            cin >> s;
            s--;
            cout << b.sum(a[s], e[s]-1) << endl;
        }
    }

}
