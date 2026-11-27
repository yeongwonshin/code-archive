#include <iostream>
#include <queue>
#include <string>
#include <utility>
/*N×M 크기의 미로가 주어진다.

미로에서 1은 이동할 수 있는 칸을 나타내고, 0은 이동할 수 없는 칸을 나타낸다.

출발점 (1, 1)에서 도착점 (N, M)까지 이동할 때 지나야 하는 최소 칸의 개수를 구하시오.

단, 다음 조건을 만족해야 한다.
- 상하좌우로 인접한 칸으로만 이동할 수 있다.
- 대각선으로 이동할 수 없다.
- 0으로 표시된 칸은 지나갈 수 없다.
- 출발점과 도착점도 지나간 칸의 개수에 포함한다.
- 도착점까지 이동할 수 있는 경로가 항상 존재한다.
*/
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