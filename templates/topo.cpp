#include "template.cpp"

/*
 * Topological sort
 *
 * sorts vertices in a directed graph such that if theres an edge a -> b, then
 * a comes before b
 * * it works on a dag only
 * * suitable for dp
 */

vi toposort(vvi& G) {
    int N = G.size();
    vi ret;
    ret.reserve(N);
    vb vis(N);

    auto topo = [&](auto& topo, int u) -> void {
        if (vis[u]) return;
        vis[u] = true;
        for (int o : G[u]) {
            topo(topo, o);
        }
        ret.push_back(u);
    };

    for (int i = 0; i < N; i++) {
        topo(topo, i);
    }

    reverse(ret.begin(), ret.end());
    return ret;
}

/*
 * Kahn's topological sort algorithm. its a dfs version of the above
 * you can use a pqueue instead of queue to prioritize lower-value vertices
 */

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
