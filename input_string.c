/*
3
hello world
I like C language
this is third line*/
#include <stdio.h>
#include <string.h>

int main(void) {
    int N;
    char line[1000];

    scanf("%d", &N);
    getchar();  // 숫자 입력 뒤에 남은 엔터 제거

    for (int i = 0; i < N; i++) {
        fgets(line, sizeof(line), stdin);

        line[strcspn(line, "\n")] = '\0';  // 끝의 엔터 제거

        printf("%d번째 줄: %s\n", i + 1, line);
    }

    return 0;
}
