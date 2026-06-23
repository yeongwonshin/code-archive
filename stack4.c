/*
4. BOJ 3015 — 오아시스 재결합

한 줄로 서 있는 사람들 중 서로 볼 수 있는 쌍의 개수를 구한다. 두 사람 사이에 두 사람 중 한 명보다 키가 큰 사람이 있으면 서로 볼 수 없다. 같은 키가 많이 나올 수 있으므로, 스택에 키만 넣으면 느려질 수 있다. 따라서 {키, 같은 키 사람 수} 형태로 압축해서 저장한다. 결과가 매우 커질 수 있으므로 long long이 필요하다.

예시 입력
7
2
4
1
2
2
5
1
예시 출력
10*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int height;
    int count;
} PersonGroup;

int main(void) {
    int N;
    scanf("%d", &N);

    PersonGroup *stack = (PersonGroup *)malloc(sizeof(PersonGroup) * N);
    int top = 0;
    long long answer = 0;

    for (int i = 0; i < N; i++) {
        int h;
        scanf("%d", &h);

        int same_count = 1;

        while (top > 0 && stack[top - 1].height < h) {
            answer += stack[top - 1].count;
            top--;
        }

        if (top > 0 && stack[top - 1].height == h) {
            answer += stack[top - 1].count;
            same_count = stack[top - 1].count + 1;
            top--;

            if (top > 0) {
                answer++;
            }
        } else {
            if (top > 0) {
                answer++;
            }
        }

        stack[top].height = h;
        stack[top].count = same_count;
        top++;
    }

    printf("%lld\n", answer);

    free(stack);

    return 0;
}