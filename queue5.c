/*5. BOJ 1966 — 프린터 큐

문서들이 큐에 들어 있고, 각 문서에는 중요도가 있다.
큐의 맨 앞 문서보다 중요도가 높은 문서가 뒤에 있으면, 맨 앞 문서를 출력하지 않고 다시 큐의 뒤로 보낸다. 그렇지 않으면 출력한다. 특정 문서가 몇 번째로 출력되는지 구하는 문제다.

핵심

큐 앞 문서보다 높은 중요도가 있으면:

pop 후 push

높은 중요도가 없으면:

pop 후 출력 순서 증가*/
#include <stdio.h>

#define MAX 105

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);

        int priority[MAX];
        int index[MAX];

        int front = 0;
        int rear = 0;
        int size = 0;

        for (int i = 0; i < n; i++) {
            int p;
            scanf("%d", &p);

            priority[rear] = p;
            index[rear] = i;
            rear = (rear + 1) % MAX;
            size++;
        }

        int count = 0;

        while (1) {
            int cur_p = priority[front];
            int cur_idx = index[front];

            int has_higher = 0;

            for (int i = 0; i < size; i++) {
                int pos = (front + i) % MAX;
                if (priority[pos] > cur_p) {
                    has_higher = 1;
                    break;
                }
            }

            if (has_higher) {
                front = (front + 1) % MAX;
                size--;

                priority[rear] = cur_p;
                index[rear] = cur_idx;
                rear = (rear + 1) % MAX;
                size++;
            }
            else {
                front = (front + 1) % MAX;
                size--;
                count++;

                if (cur_idx == m) {
                    printf("%d\n", count);
                    break;
                }
            }
        }
    }

    return 0;
}