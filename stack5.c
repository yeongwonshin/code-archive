/*
5. BOJ 6549 — 히스토그램에서 가장 큰 직사각형

여러 개의 히스토그램 막대가 주어졌을 때 만들 수 있는 가장 큰 직사각형의 넓이를 구한다. 단순히 모든 구간을 보면 O(N^2)라서 시간 초과가 난다. 스택에는 높이가 증가하는 막대의 인덱스를 저장하고, 현재 막대가 더 낮아지는 순간 이전 막대들이 만들 수 있는 최대 넓이를 계산한다. 넓이는 long long으로 처리해야 한다.

예시 입력
7 2 1 4 5 1 3 3
4 1000 1000 1000 1000
0
예시 출력
8
4000*/
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;

    while (scanf("%d", &n) == 1) {
        if (n == 0) break;

        long long *height = (long long *)malloc(sizeof(long long) * n);
        int *stack = (int *)malloc(sizeof(int) * n);

        for (int i = 0; i < n; i++) {
            scanf("%lld", &height[i]);
        }

        int top = 0;
        long long max_area = 0;

        for (int i = 0; i <= n; i++) {
            long long current_height;

            if (i == n) {
                current_height = 0;
            } else {
                current_height = height[i];
            }

            while (top > 0 && height[stack[top - 1]] > current_height) {
                int idx = stack[--top];
                long long h = height[idx];

                int left_index;
                if (top == 0) {
                    left_index = -1;
                } else {
                    left_index = stack[top - 1];
                }

                long long width = i - left_index - 1;
                long long area = h * width;

                if (area > max_area) {
                    max_area = area;
                }
            }

            if (i < n) {
                stack[top++] = i;
            }
        }

        printf("%lld\n", max_area);

        free(height);
        free(stack);
    }

    return 0;
}
