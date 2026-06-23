/*4. BOJ 11866 — 요세푸스 문제 0

1번부터 N번까지 사람이 원형으로 앉아 있다.
앞에서부터 K번째 사람을 제거하고, 제거 순서를 출력하는 문제다. 큐로 풀면 K - 1명은 뒤로 보내고, K번째 사람은 제거하면 된다.
(원형 큐 문제)
핵심

예를 들어 K = 3이면:

앞 사람 2명은 뒤로 보냄
3번째 사람은 출력하고 제거*/

//큐 안에 있는 사람 수 : size

#include <stdio.h>

#define MAX 1005

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int q[MAX];
    int front = 0;
    int rear = 0;
    int size = 0;

    for (int i = 1; i <= n; i++) {
        q[rear] = i;
        rear = (rear + 1) % MAX;
        size++;
    }

    printf("<");

    while (size > 0) {
    /*일반적으로 while(front < rear)를 쓴다. 단, 이건 큐가 비어있는지 확인할 때에만 
    씀. 즉, front, rear가 계속 증가하는 상황일 때에만 사용. but 원형큐에서는 size로 봐야.*/
        for (int i = 0; i < k - 1; i++) {
            int x = q[front];
            front = (front + 1) % MAX;
   
            q[rear] = x;
            rear = (rear + 1) % MAX;
        }

        int removed = q[front];
        front = (front + 1) % MAX;
        size--;

        printf("%d", removed);

        if (size > 0) printf(", ");
    }

    printf(">\n");

    return 0;
}
