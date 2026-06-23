/*3. BOJ 2164 — 카드2

1부터 N까지 카드가 큐에 들어 있다.
반복 규칙은 다음과 같다.

맨 앞 카드를 버린다.
그다음 맨 앞 카드를 맨 뒤로 보낸다.
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int *q = (int *)malloc(sizeof(int) * (2 * n + 5));

    int front = 0;
    int rear = 0;

    for (int i = 1; i <= n; i++) {
        q[rear++] = i;
    }

    while (rear - front > 1) {
        front++;

        q[rear++] = q[front];
        front++;
    }

    printf("%d\n", q[front]);

    free(q);

    return 0;
}
