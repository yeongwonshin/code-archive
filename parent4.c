/*

4. BOJ 5213 — 과외맨

도미노 타일들이 특수한 형태로 배치되어 있고, 인접한 조각의 숫자가 같을 때만 다른 타일로 이동할 수 있다.
 1번 타일부터 마지막 타일까지의 가장 짧은 타일 번호 경로를 출력하고, 마지막 타일에 못 가면 도달 가능한 번호가 가장 큰 타일까지의 경로를 출력한다.
 BFS로 타일 그래프를 탐색하면서 parent[다음타일] = 현재타일을 저장하면 된다.
*/
#include <stdio.h>
#include <string.h>

#define MAXN 500
#define MAXC 1000
#define MAXT 250005
#define MAXD 8

int val[MAXN][MAXC];
int tid[MAXN][MAXC];

int adj[MAXT][MAXD];
int deg[MAXT];

int parent[MAXT];
int visited[MAXT];
int queue_arr[MAXT];
int path[MAXT];

void add_edge(int a, int b) {
    if (a == b) return;

    for (int i = 0; i < deg[a]; i++) {
        if (adj[a][i] == b) return;
    }

    if (deg[a] < MAXD) {
        adj[a][deg[a]++] = b;
    }
}

int main(void) {
    int N;
    scanf("%d", &N);

    int tile = 1;

    for (int r = 0; r < N; r++) {
        if (r % 2 == 0) {
            for (int j = 0; j < N; j++) {
                int a, b;
                scanf("%d %d", &a, &b);

                int c = j * 2;

                val[r][c] = a;
                val[r][c + 1] = b;

                tid[r][c] = tile;
                tid[r][c + 1] = tile;

                tile++;
            }
        } else {
            for (int j = 0; j < N - 1; j++) {
                int a, b;
                scanf("%d %d", &a, &b);

                int c = j * 2 + 1;

                val[r][c] = a;
                val[r][c + 1] = b;

                tid[r][c] = tile;
                tid[r][c + 1] = tile;

                tile++;
            }
        }
    }

    int total = tile - 1;
    int cols = 2 * N;

    int dr[2] = {0, 1};
    int dc[2] = {1, 0};

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < cols; c++) {
            if (tid[r][c] == 0) continue;

            for (int d = 0; d < 2; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];

                if (nr < 0 || nr >= N || nc < 0 || nc >= cols) continue;
                if (tid[nr][nc] == 0) continue;
                if (tid[r][c] == tid[nr][nc]) continue;
                if (val[r][c] != val[nr][nc]) continue;

                add_edge(tid[r][c], tid[nr][nc]);
                add_edge(tid[nr][nc], tid[r][c]);
            }
        }
    }

    int front = 0, rear = 0;

    queue_arr[rear++] = 1;
    visited[1] = 1;
    parent[1] = 0;

    int best = 1;

    while (front < rear) {
        int cur = queue_arr[front++];

        if (cur > best) best = cur;

        for (int i = 0; i < deg[cur]; i++) {
            int nx = adj[cur][i];

            if (visited[nx]) continue;

            visited[nx] = 1;
            parent[nx] = cur;
            queue_arr[rear++] = nx;
        }
    }

    int cnt = 0;
    int cur = best;

    while (cur != 0) {
        path[cnt++] = cur;
        cur = parent[cur];
    }

    printf("%d\n", cnt);

    for (int i = cnt - 1; i >= 0; i--) {
        printf("%d ", path[i]);
    }
    printf("\n");

    return 0;
}