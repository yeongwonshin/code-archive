/*
4. 백준 1012 — 유기농 배추

관련 포인트:
여러 개의 테스트 케이스에서 격자 DFS를 반복한다. “갈 수 있는 칸을 타고 계속 깊게 들어간다”는 점에서 미로 DFS와 같다. 상하좌우로 인접한 배추 묶음마다 지렁이 1마리가 필요하므로 연결 컴포넌트 개수를 구한다.

1. 문제 설명
어떤 배추밭에는 유기농 배추가 심어져 있다. 배추에는 해충이 발생할 수 있는데, 배추흰지렁이를 배치하면 해충으로부터 배추를 보호할 수 있다.
배추흰지렁이는 자신이 위치한 배추뿐만 아니라 상하좌우로 인접하여 연결된 모든 배추로 이동할 수 있다.
따라서 서로 연결된 배추들은 배추흰지렁이 한 마리로 보호할 수 있다.
배추밭의 가로 길이 \(M\), 세로 길이 \(N\), 배추가 심어진 위치 \(K\)개가 주어질 때, 모든 배추를 보호하기 위해 필요한 배추흰지렁이의 최소 마릿수를 구하는 프로그램을 작성하시오.
2. 입력
첫 번째 줄에는 테스트 케이스의 개수 \(T\)가 주어진다.
각 테스트 케이스는 다음과 같이 구성된다.
- 첫 번째 줄: 배추밭의 가로 길이 \(M\), 세로 길이 \(N\), 배추 개수 \(K\)
- 다음 \(K\)개의 줄: 각 배추의 좌표 \(x,y\)
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
        /*field, vistied를 전역변수로 선언했기에 이미 0으로 초기화되어있지만,
         테스트케이스마다 초기화해주기 위해 memset을 사용한다.
*/
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