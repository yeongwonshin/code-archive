/*1. 백준 1260 — DFS와 BFS

관련 포인트:
DFS 방문 순서를 출력하는 기본 문제다. “S에서 시작해서 DFS로 어디를 먼저 가는가”를 익히기 좋다. 방문할 수 있는 정점이 여러 개면 번호가 작은 정점부터 방문한다.

문제 요약

정점 N개, 간선 M개, 시작 정점 V가 주어진다.
DFS 방문 순서와 BFS 방문 순서를 각각 출력한다.*/
#include <stdio.h>
#include <string.h>

int N, M, V;
int graph[1001][1001];
int visited[1001];

void dfs(int x) {
    visited[x] = 1;
    printf("%d ", x);

    for (int i = 1; i <= N; i++) {
        if (graph[x][i] && !visited[i]) {
            dfs(i);
        }
    }
}

void bfs(int start) {
    int queue[1001];
    int front = 0, rear = 0;

    memset(visited, 0, sizeof(visited));

    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int cur = queue[front++];
        printf("%d ", cur);

        for (int i = 1; i <= N; i++) {
            if (graph[cur][i] && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main(void) {
    scanf("%d %d %d", &N, &M, &V);

    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    dfs(V);
    printf("\n");
    bfs(V);

    return 0;
}