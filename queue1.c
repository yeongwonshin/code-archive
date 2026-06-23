#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    int q[10005];
    int front = 0;
    int rear = 0;

    char cmd[20];

    for (int i = 0; i < n; i++) {
        scanf("%s", cmd);

        if (strcmp(cmd, "push") == 0) {
            int x;
            scanf("%d", &x);
            q[rear++] = x;
        }
        else if (strcmp(cmd, "pop") == 0) {
            if (front == rear) {
                printf("-1\n");
            } else {
                printf("%d\n", q[front++]);
            }
        }
        else if (strcmp(cmd, "size") == 0) {
            printf("%d\n", rear - front);
        }
        else if (strcmp(cmd, "empty") == 0) {
            if (front == rear) printf("1\n");
            else printf("0\n");
        }
        else if (strcmp(cmd, "front") == 0) {
            if (front == rear) printf("-1\n");
            else printf("%d\n", q[front]);
        }
        else if (strcmp(cmd, "back") == 0) {
            if (front == rear) printf("-1\n");
            else printf("%d\n", q[rear - 1]);
        }
    }

    return 0;
}