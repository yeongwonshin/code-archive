/*1. BOJ 13913 — 숨바꼭질 4

수빈이가 위치 N에서 시작해서 K까지 가야 한다. 한 번에 X-1, X+1, 2*X로 이동할 수 있고, 최단 시간과 실제 이동 경로를 출력해야 한다. 출력 둘째 줄에 “어떻게 이동해야 하는지”를 출력하므로 parent[next] = current가 정석이다.
*/
#include <stdio.h>
#include <string.h>

#define MAX 100000

int dist_arr[MAX + 1];
int parent[MAX + 1];
int queue_arr[MAX + 1];
int path[MAX + 1];

int main(void) {
    int N, K;
    scanf("%d %d", &N, &K);

    for (int i = 0; i <= MAX; i++) {
        dist_arr[i] = -1;
        parent[i] = -1;
    }

    int front = 0, rear = 0;
    queue_arr[rear++] = N;
    dist_arr[N] = 0;
    parent[N] = N;

    while (front < rear) {
        int x = queue_arr[front++];

        if (x == K) break;

        int nexts[3] = {x - 1, x + 1, x * 2};

        for (int i = 0; i < 3; i++) {
            int nx = nexts[i];

            if (nx < 0 || nx > MAX) continue;
            if (dist_arr[nx] != -1) continue;

            dist_arr[nx] = dist_arr[x] + 1;
            parent[nx] = x;
            queue_arr[rear++] = nx;
        }
    }

    printf("%d\n", dist_arr[K]);

    int cnt = 0;
    int cur = K;

    while (cur != N) {
        path[cnt++] = cur;
        cur = parent[cur];
    }
    path[cnt++] = N;

    for (int i = cnt - 1; i >= 0; i--) {
        printf("%d ", path[i]);
    }
    printf("\n");

    return 0;
}