/*
2. 백준 2178 — 미로 탐색

관련 포인트:
미로에서 시작점 (1,1)에서 도착점 (N,M)까지 가는 문제다. 
네가 말한 “S에서 G까지”와 가장 비슷하다. 다만 이 문제는 최단거리를 요구하므로 DFS가 아니라 BFS를 써야 한다.
 DFS는 도착은 찾을 수 있지만 최단거리 보장은 안 된다.
*/
#include <stdio.h>
#include <string.h>

int N, M;
int maze[101][101];
int dist[101][101];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

typedef struct {
    int x;
    int y;
} Node;

Node queue[10000];

int main(void) {
    scanf("%d %d", &N, &M);

    char line[105];

    for (int i = 0; i < N; i++) {
        scanf("%s", line);
        for (int j = 0; j < M; j++) {
            maze[i][j] = line[j] - '0';
        }
    }

    int front = 0, rear = 0;

    queue[rear++] = (Node){0, 0};
    dist[0][0] = 1;

    while (front < rear) {
        Node cur = queue[front++];

        for (int d = 0; d < 4; d++) {
            int nx = cur.x + dx[d];
            int ny = cur.y + dy[d];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (maze[nx][ny] == 0) continue;
            if (dist[nx][ny] != 0) continue;

            dist[nx][ny] = dist[cur.x][cur.y] + 1;
            queue[rear++] = (Node){nx, ny};
        }
    }

    printf("%d\n", dist[N - 1][M - 1]);

    return 0;
}