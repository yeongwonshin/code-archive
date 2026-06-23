/*. BOJ 9019 — DSLR

정수 A를 B로 바꾸는 가장 짧은 명령어 문자열을 출력하는 문제다. 명령은 D, S, L, R 네 가지이고, BFS로 숫자 상태를 탐색한다. 
상태마다 parent[다음숫자] = 현재숫자, how[다음숫자] = 사용한 명령을 저장하면 명령어 경로를 복원할 수 있다*/
#include <stdio.h>
#include <string.h>

#define MAX 10000

int parent[MAX];
int visited[MAX];
int queue_arr[MAX];
char how[MAX];
char answer[MAX];

int calc_next(int x, int type) {
    if (type == 0) return (x * 2) % 10000;              // D
    if (type == 1) return (x == 0) ? 9999 : x - 1;      // S
    if (type == 2) return (x % 1000) * 10 + x / 1000;   // L
    return (x % 10) * 1000 + x / 10;                    // R
}

int main(void) {
    int T;
    scanf("%d", &T);

    while (T--) {
        int A, B;
        scanf("%d %d", &A, &B);

        for (int i = 0; i < MAX; i++) {
            visited[i] = 0;
            parent[i] = -1;
            how[i] = 0;
        }

        int front = 0, rear = 0;
        queue_arr[rear++] = A;
        visited[A] = 1;
        parent[A] = A;

        char op[4] = {'D', 'S', 'L', 'R'};

        while (front < rear) {
            int x = queue_arr[front++];

            if (x == B) break;

            for (int i = 0; i < 4; i++) {
                int nx = calc_next(x, i);

                if (visited[nx]) continue;

                visited[nx] = 1;
                parent[nx] = x;
                how[nx] = op[i];
                queue_arr[rear++] = nx;
            }
        }

        int len = 0;
        int cur = B;

        while (cur != A) {
            answer[len++] = how[cur];
            cur = parent[cur];
        }

        for (int i = len - 1; i >= 0; i--) {
            putchar(answer[i]);
        }
        putchar('\n');
    }

    return 0;
}