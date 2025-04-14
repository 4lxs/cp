#include <bits/stdc++.h>
#include <limits>
#include <stdexcept>
using namespace std;

signed main() {
    int N, M;
    cin >> N >> M;

    vector<vector<char>> G(N, vector<char>(M));
    int ax, ay;
    for (auto& v : G) for (auto& i : v) cin >> i;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (G[i][j] == 'A') ay = i, ax = j;

    vector<vector<int>> d(N, vector<int>(M, numeric_limits<int>::max()));
    int bx = -1, by;
    d[ay][ax] = 0;
    queue<tuple<int, int>> q;
    q.push({ax, ay});
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();

        for (auto [nx, ny, dir] : {tuple<int, int, char>{x + 1, y, 'R'}, {x - 1, y, 'L'}, {x, y + 1, 'D'}, {x, y - 1, 'U'}}) {
            if (nx < 0 || nx == M || ny < 0 || ny == N) continue;
            if (G[ny][nx] == 'B') {
                bx = nx, by = ny;
                d[ny][nx] = d[y][x] + 1;
                goto out;
            }
            if (G[ny][nx] != '.') continue;
            d[ny][nx] = d[y][x] + 1;
            G[ny][nx] = 'd';
            q.push({nx, ny});
        }
    }

out:;
    if (bx == -1) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    cout << d[by][bx] << endl;
    string ans;
    int x = bx, y = by;
    while (d[by][bx]) {
        for (auto [nx, ny, dir] : {tuple<int, int, char>{bx + 1, by, 'L'}, {bx - 1, by, 'R'}, {bx, by + 1, 'U'}, {bx, by - 1, 'D'}}) {
            if (nx < 0 || nx == M || ny < 0 || ny == N) continue;
            if (d[ny][nx] == d[by][bx] - 1) {
                ans.push_back(dir);
                by = ny, bx = nx;
                goto end;
            }
        }
        throw runtime_error("fuck");
end:;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}
