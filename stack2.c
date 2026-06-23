/*2. BOJ 17299 — 오등큰수

오큰수의 변형이다. 값 자체가 큰지를 보는 것이 아니라, 등장 횟수가 더 큰 수를 찾는다. F(x)를 수 x의 등장 횟수라고 할 때, Ai의 오른쪽에서 F(Ai)보다 등장 횟수가 큰 가장 왼쪽 값을 출력한다. 없으면 -1이다.

예시 입력
7
1 1 2 3 4 2 1
예시 출력
-1 -1 1 2 2 1 -1
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_VALUE 1000000

int main(void) {
    int N;
    scanf("%d", &N);

    int *arr = (int *)malloc(sizeof(int) * N);
    int *ans = (int *)malloc(sizeof(int) * N);
    int *stack = (int *)malloc(sizeof(int) * N);
    int *freq = (int *)calloc(MAX_VALUE + 1, sizeof(int));

    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
        freq[arr[i]]++;
        ans[i] = -1;
    }

    int top = 0;

    for (int i = 0; i < N; i++) {
        while (top > 0 && freq[arr[stack[top - 1]]] < freq[arr[i]]) {
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
    free(freq);

    return 0;
}