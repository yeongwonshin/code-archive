/*
5. BOJ 11779 — 최소비용 구하기 2

이 문제는 BFS가 아니라 다익스트라다. 하지만 “최단 경로를 구하고, 그 경로의 정점들을 출력한다”는 점에서 parent[] 복원 연습으로 매우 좋다. 
최소 비용, 경로에 포함된 도시 개수, 방문 도시 순서를 출력해야 한다.
*/

#include <stdio.h>
#include <string.h>

#define MAXN 1000
#define MAXM 100000
#define INF 4000000000000000000LL

typedef struct {
    int to;
    int cost;
    int next;
} Edge;

Edge edges[MAXM + 5];

int head[MAXN + 1];
int edge_count = 0;

long long dist_arr[MAXN + 1];
int visited[MAXN + 1];
int parent[MAXN + 1];
int path[MAXN + 1];

void add_edge(int u, int v, int w) {
    edges[edge_count].to = v;
    edges[edge_count].cost = w;
    edges[edge_count].next = head[u];
    head[u] = edge_count++;
}

int main(void) {
    int n, m;

    scanf("%d", &n);
    scanf("%d", &m);

    for (int i = 1; i <= n; i++) {
        head[i] = -1;
    }

    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);

        add_edge(a, b, c);
    }

    int start, target;
    scanf("%d %d", &start, &target);

    for (int i = 1; i <= n; i++) {
        dist_arr[i] = INF;
        visited[i] = 0;
        parent[i] = 0;
    }

    dist_arr[start] = 0;
    parent[start] = start;

    for (int iter = 0; iter < n; iter++) {
        int u = -1;
        long long best = INF;

        for (int i = 1; i <= n; i++) {
            if (!visited[i] && dist_arr[i] < best) {
                best = dist_arr[i];
                u = i;
            }
        }

        if (u == -1) break;

        visited[u] = 1;

        if (u == target) break;

        for (int e = head[u]; e != -1; e = edges[e].next) {
            int v = edges[e].to;
            int w = edges[e].cost;

            if (dist_arr[v] > dist_arr[u] + w) {
                dist_arr[v] = dist_arr[u] + w;
                parent[v] = u;
            }
        }
    }

    int cnt = 0;
    int cur = target;

    while (cur != start) {
        path[cnt++] = cur;
        cur = parent[cur];
    }

    path[cnt++] = start;

    printf("%lld\n", dist_arr[target]);
    printf("%d\n", cnt);

    for (int i = cnt - 1; i >= 0; i--) {
        printf("%d ", path[i]);
    }
    printf("\n");

    return 0;
}