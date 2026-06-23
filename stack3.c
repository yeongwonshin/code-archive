/*3. BOJ 2493 — 탑

탑들이 왼쪽부터 오른쪽으로 서 있고, 각 탑은 왼쪽 방향으로 레이저를 쏜다. 각 탑의 레이저를 가장 먼저 수신하는 왼쪽 탑의 번호를 출력한다. 없으면 0을 출력한다. 스택에는 “오른쪽 탑들의 레이저를 받을 가능성이 있는 탑”만 남긴다.

예시 입력
5
6 9 5 7 4
예시 출력
0 0 2 2 4*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int index;
    int height;
} Tower;

int main(void) {
    int N;
    scanf("%d", &N);

    Tower *stack = (Tower *)malloc(sizeof(Tower) * N);
    int top = 0;

    for (int i = 1; i <= N; i++) {
        int h;
        scanf("%d", &h);

        while (top > 0 && stack[top - 1].height < h) {
            top--;
        }

        if (top == 0) {
            printf("0");
        } else {
            printf("%d", stack[top - 1].index);
        }

        if (i < N) printf(" ");

        stack[top].index = i;
        stack[top].height = h;
        top++;
    }

    free(stack);

    return 0;
}