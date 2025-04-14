#include "template.cpp"

/** shortest path algorithms
 *
 * if given end vertex, we can reverse the edges (directed) and solve it as if
 * it was start
 *
 * # dag
 *
 * shortest path on a dag is O(V + E) trivial
 *
 * # state-space graph
 * 
 * when a vertex needs to contain information (e.g. fuel) and we need to represent
 * the graph as (vertex, fuel) with the final graph being #vertices * #states
 */

/** unweighted
 *
 * we can do a bfs. if we only have single destination (sssdsp)
 * we can stop (prune) when we get to the destination
 *
 * if working with multiple sources, we can enqueue all the sources at the start
 * (you can just imagine a virtual start vertex, that is connected to all the
 * starts with 0 edges)
 *
 * # knight moves
 *
 * we can use a bfs. if we have multiple queries, we can, due to symmetry of the
 * board, only do one bfs and shift by constant for all the answers ((1, 1) ->
 * (5, 3) == (2, 2) -> (6, 4))
 *
 * # 0-1 weighted
 *
 * use bfs as in unweighted, but use dequeue instead of a queue and push
 * 0-weighted to the front and 1-weighted to the end
 */

/** weighted without negative weight cycles (dijkstra)
 *
 * works with negative weights assuming no negative weight cycles (which is
 * considered an ill-formed problem)
 *
 * is O(N + M log(N))
 * Can be done in O(M + N log(N)) with fibonacci heaps, but in practice rarely faster
 */
vi dijkstra(vvpii& G, int s) {
  vi dist(G.size(), inf);
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

/** weighted with negative weight cycles (bellman ford, bellman-ford-moore)
 * 
 * slower than dijkstra, but it can detect negative weight cycles (dijkstra loops),
 * though that should be considered an ill-formed problem
 */

/** all-pairs shortest path (apsp) on weighted graph (floyd-warshall)
 *
 * the floyd-warshall is faster to code than dijkstra (O(V^3) vs O(V(V+E) log
 * V))
 *
 * its a dp algorithm on dp(k, i, j) = "shortest distance i -> j using [0..k] as
 * vertices". dp(-1, 0, 0) = weight(i, j). dp(k, i, j) = min(dp(k - 1, i, j),
  dp(k - 1, i, k) + dp(k
 *
 * # other applications
 *
 * - minimax maximin problem
 * - finding the cheapest/negative cycle
 * - finding the diameter of the graph
 * - finding scc
 */
