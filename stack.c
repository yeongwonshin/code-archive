/*
1. BOJ 17298 — 오큰수

각 원소 Ai에 대해, 오른쪽에 있으면서 Ai보다 큰 수 중 가장 왼쪽에 있는 수를 출력한다. 
없으면 -1을 출력한다. 스택에는 “아직 오큰수를 못 찾은 인덱스”를 저장한다
예시 입력
4
3 5 2 7
예시 출력
5 7 7 -1*/
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int N;
    scanf("%d", &N);

    int *arr = (int *)malloc(sizeof(int) * N);
    int *ans = (int *)malloc(sizeof(int) * N);
    int *stack = (int *)malloc(sizeof(int) * N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
        ans[i] = -1;
    }

    int top = 0;

    for (int i = 0; i < N; i++) {
        while (top > 0 && arr[stack[top - 1]] < arr[i]) {
            int idx = stack[--top];
            ans[idx] = arr[i];
        }
        stack[top++] = i;
    }

    for (int i = 0; i < N; i++) {
        printf("%d", ans[i]);
        if (i + 1 < N) printf(" ");
    }

    free(arr);
    free(ans);
    free(stack);

    return 0;
}