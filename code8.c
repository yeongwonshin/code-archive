/*
백준 1063 — 킹 문제 요약

체스판은 8 × 8이고, 좌표는 다음처럼 주어진다.

A1 B1 C1 ... H1
A2 B2 C2 ... H2
...
A8 B8 C8 ... H8

킹과 돌의 초기 위치가 주어지고, 명령 N개가 주어진다.

킹은 명령에 따라 8방향으로 한 칸 이동한다.

R   : 오른쪽
L   : 왼쪽
B   : 아래
T   : 위
RT  : 오른쪽 위
LT  : 왼쪽 위
RB  : 오른쪽 아래
LB  : 왼쪽 아래

이동하려는 칸에 돌이 있으면, 킹이 돌을 같은 방향으로 민다.

단, 다음 경우에는 명령을 무시한다.

킹이 체스판 밖으로 나가는 경우
돌을 밀었는데 돌이 체스판 밖으로 나가는 경우

모든 명령 처리 후 킹과 돌의 최종 위치를 출력한다.
**입력: 킹의 위치, 돌의 위치, 명령 개수
**출력 : 킹의 최종 위치, 돌의 최종 위치
예제 입력 1
A1 A2 1
T
예제 출력 1
A2
A3

설명:

킹: A1 → A2
돌이 A2에 있으므로 돌도 위로 밀림
돌: A2 → A3

예제 입력 2
A1 A2 5
B
L
LB
RB
LT
예제 출력 2
A1
A2

설명:

처음 킹: A1
처음 돌: A2

B  : 킹이 A0으로 나가므로 무시
L  : 킹이 체스판 밖으로 나가므로 무시
LB : 체스판 밖으로 나가므로 무시
RB : 체스판 밖으로 나가므로 무시
LT : 체스판 밖으로 나가므로 무시

따라서 위치 변화 없음*/
#include <stdio.h>
#include <string.h>

int in_range(int x, int y) {
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}

void get_direction(char cmd[], int *dx, int *dy) {
    *dx = 0;
    *dy = 0;

    if (strcmp(cmd, "R") == 0) {
        *dx = 1;
        *dy = 0;
    }
    else if (strcmp(cmd, "L") == 0) {
        *dx = -1;
        *dy = 0;
    }
    else if (strcmp(cmd, "B") == 0) {
        *dx = 0;
        *dy = -1;
    }
    else if (strcmp(cmd, "T") == 0) {
        *dx = 0;
        *dy = 1;
    }
    else if (strcmp(cmd, "RT") == 0) {
        *dx = 1;
        *dy = 1;
    }
    else if (strcmp(cmd, "LT") == 0) {
        *dx = -1;
        *dy = 1;
    }
    else if (strcmp(cmd, "RB") == 0) {
        *dx = 1;
        *dy = -1;
    }
    else if (strcmp(cmd, "LB") == 0) {
        *dx = -1;
        *dy = -1;
    }
}

int main(void) {
    char king_pos[3];
    char stone_pos[3];
    int N;

    scanf("%s %s %d", king_pos, stone_pos, &N);

    int king_x = king_pos[0] - 'A';
    int king_y = king_pos[1] - '1';

    int stone_x = stone_pos[0] - 'A';
    int stone_y = stone_pos[1] - '1';

    for (int i = 0; i < N; i++) {
        char cmd[3];
        scanf("%s", cmd);

        int dx, dy;
        get_direction(cmd, &dx, &dy);

        int next_king_x = king_x + dx;
        int next_king_y = king_y + dy;

        if (!in_range(next_king_x, next_king_y)) {
            continue;
        }

        if (next_king_x == stone_x && next_king_y == stone_y) {
            int next_stone_x = stone_x + dx;
            int next_stone_y = stone_y + dy;

            if (!in_range(next_stone_x, next_stone_y)) {
                continue;
            }

            stone_x = next_stone_x;
            stone_y = next_stone_y;
        }

        king_x = next_king_x;
        king_y = next_king_y;
    }

    printf("%c%c\n", king_x + 'A', king_y + '1');
    printf("%c%c\n", stone_x + 'A', stone_y + '1');

    return 0;
}
