#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    int *q = (int *)malloc(sizeof(int) * (n + 5));
    char *out = (char *)malloc(sizeof(char) * (n * 12 + 5));

    int front = 0;
    int rear = 0;
    int out_idx = 0;

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
                out_idx += sprintf(out + out_idx, "-1\n");
                //sprintf반환값: 출력된 문자열의 길이
            } else {
                out_idx += sprintf(out + out_idx, "%d\n", q[front++]);
            }
        }
        else if (strcmp(cmd, "size") == 0) {
            out_idx += sprintf(out + out_idx, "%d\n", rear - front);
        }
        else if (strcmp(cmd, "empty") == 0) {
            if (front == rear) out_idx += sprintf(out + out_idx, "1\n");
            else out_idx += sprintf(out + out_idx, "0\n");
        }
        else if (strcmp(cmd, "front") == 0) {
            if (front == rear) {
                out_idx += sprintf(out + out_idx, "-1\n");
            } else {
                out_idx += sprintf(out + out_idx, "%d\n", q[front]);
            }
        }
        else if (strcmp(cmd, "back") == 0) {
            if (front == rear) {
                out_idx += sprintf(out + out_idx, "-1\n");
            } else {
                out_idx += sprintf(out + out_idx, "%d\n", q[rear - 1]);
            }
        }
    }

    printf("%s", out);

    free(q);
    free(out);

    return 0;
}