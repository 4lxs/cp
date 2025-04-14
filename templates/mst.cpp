#include "template.cpp"

/** Minimum spanning tree (mst)
 *
 * problem: find subset of edges such that the graph stays connected and
 * minimizes edge weight total
 *
 * # minimax problem
 *
 * problem: among all possible paths between two vertices, find the one with
 * minimum max-edge-weight
 *
 * you can solve it simply by outputting the unique path in mst
 */

/** kruskal's algorithm (E log(V))
 *
 * uses edge-list graph data structure
 * sort edges on non-decreasing weight and greedily add smallest weight edge
 * that doesn't form a cycle (using dsu)
 */

/** prim's algorithm (E log(E))
 *
 * to make it max-spanning-tree, change pq greater -> less, inf -> minf,
 * dist[x] < w -> dist[x] > w (2x)
 *
 * you can replace pq with linear scan, to make it O(V^2) (good on dense graphs)
 */

int mst_prim(vvpii& G) {
    int N = G.size();
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 0});
    vi dist(N, inf);
    dist[0] = 0;
    vb vis(N);
    int min_cost = 0, added = 0;

    while (added < N) {
        if (pq.empty()) return -1;
        auto [w, u] = pq.top(); pq.pop();
        if (dist[u] < w) continue;
        dbg(u, w);
        vis[u] = true;
        added++;
        min_cost += w;
        for (auto [o, w] : G[u]) {
            if (vis[o] || dist[o] < w) continue;
            dist[o] = w;
            pq.push({w, o});
        }
    }

    return min_cost;
}
