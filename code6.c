/*백준 7562번 — 나이트의 이동은 BFS의 대표적인 기본 문제입니다.

체스판 위에서 나이트가 현재 위치에서 목표 위치까지 가는 데 필요한 최소 이동 횟수를 구하는 문제입니다.

문제 상황

체스판 크기가 l × l입니다.

예를 들어 l = 8이면 일반 체스판처럼 좌표는 다음 범위를 가집니다.

0 <= x < 8
0 <= y < 8

입력으로 다음이 주어집니다.

현재 나이트 위치: startX, startY
목표 위치: targetX, targetY

나이트는 한 번에 다음 8방향 중 하나로 이동할 수 있습니다.

(-2, -1), (-2, +1)
(-1, -2), (-1, +2)
(+1, -2), (+1, +2)
(+2, -1), (+2, +1)

목표는 현재 위치에서 목표 위치까지 가는 최소 이동 횟수를 구하는 것입니다.
*/
#include <stdio.h>
#include <string.h>

#define MAX 300

int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

int dist[MAX][MAX];

typedef struct {
    int x;
    int y;
} Point;

Point queue[MAX * MAX];

int bfs(int l, int startX, int startY, int targetX, int targetY) {
    int front = 0;
    int rear = 0;

    memset(dist, -1, sizeof(dist));

    queue[rear++] = (Point){startX, startY};
    dist[startX][startY] = 0;

    while (front < rear) {
        Point cur = queue[front++];

        if (cur.x == targetX && cur.y == targetY) {
            return dist[cur.x][cur.y];
        }

        for (int i = 0; i < 8; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (nx < 0 || nx >= l || ny < 0 || ny >= l) {
                continue;
            }

            if (dist[nx][ny] != -1) {
                continue;
            }

            dist[nx][ny] = dist[cur.x][cur.y] + 1;
            queue[rear++] = (Point){nx, ny};
        }
    }

    return -1;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int l;
        int startX, startY;
        int targetX, targetY;

        scanf("%d", &l);
        scanf("%d %d", &startX, &startY);
        scanf("%d %d", &targetX, &targetY);

        printf("%d\n", bfs(l, startX, startY, targetX, targetY));
    }

    return 0;
}