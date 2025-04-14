#include <bits/stdc++.h>
using namespace std;

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
