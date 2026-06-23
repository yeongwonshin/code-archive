/*BOJ 1205 등수 구하기는 “새 점수가 현재 랭킹 리스트에 들어간다면 몇 등인지”를 구하는 문제다.
 현재 랭킹 리스트는 비오름차순, 즉 큰 점수부터 작은 점수 순서로 주어진다. 
 같은 점수는 같은 등수이고, 예를 들어 100 90 90 80이면 등수는 1, 2, 2, 4가 된다.
*/
#include <stdio.h>

int main(void) {
    int N, P;
    int newScore;
    int score[55];

    scanf("%d %d %d", &N, &newScore, &P);

    for (int i = 0; i < N; i++) {
        scanf("%d", &score[i]);
    }

    if (N == 0) {
        printf("1\n");
        return 0;
    }

    if (N == P && newScore <= score[N - 1]) {
        printf("-1\n");
        return 0;//랭킹 리스트가 꽉 차 있고, 새 점수가 마지막 점수보다 작거나 같으면 들어갈 수 없다.
    }

    int rank = 1;

    for (int i = 0; i < N; i++) {
        if (score[i] > newScore) {
            rank++;
        } else {
            break;
        }
    }

    printf("%d\n", rank);

    return 0;
}