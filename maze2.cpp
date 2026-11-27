#include <iostream>
#include <queue>
#include <string>
#include <utility>

using namespace std;

int N, M;
int maze[101][101];
int dist[101][101];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    string line;

    for (int i = 0; i < N; i++) {
        cin >> line;

        for (int j = 0; j < M; j++) {
            maze[i][j] = line[j] - '0';
        }
    }

    queue<pair<int, int>> q;

    q.push({0, 0});
    dist[0][0] = 1;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;

            if (maze[nx][ny] == 0)
                continue;

            if (dist[nx][ny] != 0)
                continue;

            dist[nx][ny] = dist[x][y] + 1;

            q.push({nx, ny});
        }
    }

    cout << dist[N - 1][M - 1] << '\n';

    return 0;
}