/*
문제 요약

2×N 배열이 있다.
첫 번째 줄은 숫자들로, 각 칸 주변에 있는 지뢰 개수를 의미한다.
두 번째 줄은 * 또는 #로 주어진다.

*는 지뢰가 확실한 칸이고, #는 지뢰일 수도 있고 아닐 수도 있는 숨겨진 칸이다.
주어진 숫자 조건을 만족하도록 할 때, 가능한 지뢰 개수의 최댓값을 구한다. 지뢰는 두 번째 줄에만 있다.

입력
T
N
숫자열
지뢰열
...

T는 테스트 케이스 개수, N은 배열의 크기이다.
각 테스트 케이스마다 숫자열 1줄, *, # 문자열 1줄이 주어진다.

출력

각 테스트 케이스마다 가능한 지뢰의 최대 개수를 한 줄에 출력한다.

예제 입력
1
5
12110
##*##
예제 출력
2
풀이 아이디어

이미 *로 확정된 지뢰는 먼저 반영해서 주변 숫자를 1씩 줄인다.
그다음 왼쪽부터 # 칸을 보면서, 그 칸에 지뢰를 놓아도 주변 숫자가 모두 1 이상이면 지뢰를 놓는다.
지뢰를 놓으면 영향을 받는 숫자들을 1씩 줄인다.

이렇게 왼쪽부터 가능한 한 지뢰를 놓으면 최대 개수를 얻을 수 있다.*/
#include <stdio.h>
#include <string.h>

int main(void) {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N;
        char numStr[105];
        char mine[105];
        int num[105];
        int answer = 0;

        scanf("%d", &N);
        scanf("%s", numStr);
        scanf("%s", mine);

        for (int i = 0; i < N; i++) {
            num[i] = numStr[i] - '0';
        }

        // 이미 확정된 지뢰(*) 반영
        for (int i = 0; i < N; i++) {
            if (mine[i] == '*') {
                answer++;

                for (int j = i - 1; j <= i + 1; j++) {
                    if (j >= 0 && j < N) {
                        num[j]--;
                    }
                }
            }
        }

        // 숨겨진 칸(#)에 가능한 한 지뢰 배치
        for (int i = 0; i < N; i++) {
            if (mine[i] == '#') {
                int canPlace = 1;

                for (int j = i - 1; j <= i + 1; j++) {
                    if (j >= 0 && j < N && num[j] <= 0) {
                        canPlace = 0;
                        break;
                    }
                }

                if (canPlace) {
                    answer++;

                    for (int j = i - 1; j <= i + 1; j++) {
                        if (j >= 0 && j < N) {
                            num[j]--;
                        }
                    }
                }
            }
        }

        printf("%d\n", answer);
    }

    return 0;
}