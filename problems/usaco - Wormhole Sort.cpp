#include <bits/stdc++.h>
using namespace std;

signed main() {
    int N, M;
    cin >> N >> M;

    vector<int> P(N);

    for (auto& i : P) cin >> i, i--;

    vector<vector<pair<int, int>>> G(N);
    int maxw = 0;
    for(int i = 0; i < M; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        a--, b--;
        maxw = max(maxw, w);
        G[a].push_back({b, w});
        G[b].push_back({a, w});
    }


}
