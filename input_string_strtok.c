#include <stdio.h>
#include <string.h>

int main(void) {
    int N;
    char line[1000];

    scanf("%d", &N);
    getchar();  // scanf 뒤에 남은 엔터 제거

    for (int i = 0; i < N; i++) {
        fgets(line, sizeof(line), stdin);

        // 줄 끝의 엔터 제거
        line[strcspn(line, "\n")] = '\0';

        printf("%d번째 줄:\n", i + 1);

        // 공백 단위로 자르기
        char *token = strtok(line, " ");

        while (token != NULL) {
            printf("단어: %s\n", token);
            token = strtok(NULL, " ");
        }
    }

    return 0;
}

//여러 줄을 입력받고, 각 줄마다 단어를 따로 저장하려면 이렇게 할 수 있습니다.

#include <stdio.h>
#include <string.h>

int main(void) {
    int N;
    char line[1000];

    scanf("%d", &N);
    getchar();

    for (int i = 0; i < N; i++) {
        char words[100][100];
        int count = 0;

        fgets(line, sizeof(line), stdin);
        line[strcspn(line, "\n")] = '\0';

        char *token = strtok(line, " ");

        while (token != NULL) {
            strcpy(words[count], token);
            count++;

            token = strtok(NULL, " ");
        }

        printf("%d번째 줄 단어들:\n", i + 1);

        for (int j = 0; j < count; j++) {
            printf("words[%d] = %s\n", j, words[j]);
        }
    }

    return 0;
}