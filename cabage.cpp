/*
4. 백준 1012 — 유기농 배추

관련 포인트:
여러 개의 테스트 케이스에서 격자 DFS를 반복한다. “갈 수 있는 칸을 타고 계속 깊게 들어간다”는 점에서 미로 DFS와 같다. 상하좌우로 인접한 배추 묶음마다 지렁이 1마리가 필요하므로 연결 컴포넌트 개수를 구한다.

문제 요약

배추가 심어진 위치들이 주어진다.
상하좌우로 연결된 배추 묶음의 개수를 출력한다.
*/

#include <iostream>
#include <cstring>
using namespace std;

int M, N, K;
int field[51][51];
int visited[51][51];

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void dfs(int y, int x) {
    visited[y][x] = 1;

    for (int d = 0; d < 4; d++) {
        int ny = y + dy[d];
        int nx = x + dx[d];

        if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
        if (field[ny][nx] == 0) continue;
        if (visited[ny][nx]) continue;

        dfs(ny, nx);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        cin >> M >> N >> K;

        memset(field, 0, sizeof(field));
        memset(visited, 0, sizeof(visited));

        for (int i = 0; i < K; i++) {
            int x, y;
            cin >> x >> y;
            field[y][x] = 1;
        }

        int answer = 0;

        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                if (field[y][x] == 1 && !visited[y][x]) {
                    dfs(y, x);
                    answer++;
                }
            }
        }

        cout << answer << '\n';
    }

    return 0;
}