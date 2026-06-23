/*
백준 3019번: 테트리스 정리

테트리스 필드는 C개의 열로 이루어져 있고, 각 열의 현재 높이가 주어진다. 블록 번호 P에 해당하는 테트리스 블록 하나를 떨어뜨릴 때, 블록 아래에 빈칸이 생기지 않도록 놓을 수 있는 경우의 수를 구하는 문제다. 블록은 회전할 수 있고, 필드를 벗어나면 안 된다. C는 1 이상 100 이하, 높이는 0 이상 100 이하이다.

예제 입력 1
6 5
2 1 1 1 0 1
예제 출력 1
5
예제 입력 2
5 1
0 0 0 0 0
예제 출력 2
7
풀이 아이디어

블록을 실제 2차원 배열에 떨어뜨릴 필요가 없다.

각 회전 모양마다 필요한 열 높이의 상대 패턴이 정해져 있다.
예를 들어 어떤 회전 모양이 3칸 폭을 차지하고, 필요한 상대 높이가

0 0 1

이라면, 현재 열 높이 구간이

2 2 3
5 5 6
0 0 1

처럼 최솟값을 뺐을 때 0 0 1이 되면 놓을 수 있다.

따라서 모든 위치 i에 대해:

회전 패턴의 폭만큼 열을 본다.
그 구간의 최솟값을 뺀다.
회전 패턴과 같으면 경우의 수를 1 증가시킨다.*/
#include <stdio.h>

int C, P;
int h[101];

int patterns[8][4][4] = {
    {{0}}, // dummy

    // 1번 블록
    {
        {0},
        {0, 0, 0, 0}
    },

    // 2번 블록
    {
        {0, 0}
    },

    // 3번 블록
    {
        {0, 0, 1},
        {1, 0}
    },

    // 4번 블록
    {
        {1, 0, 0},
        {0, 1}
    },

    // 5번 블록
    {
        {0, 0, 0},
        {0, 1},
        {1, 0},
        {1, 0, 1}
    },

    // 6번 블록
    {
        {0, 0, 0},
        {0, 0},
        {0, 1, 1},
        {2, 0}
    },

    // 7번 블록
    {
        {0, 0, 0},
        {0, 0},
        {1, 1, 0},
        {0, 2}
    }
};

int width[8][4] = {
    {0},
    {1, 4},
    {2},
    {3, 2},
    {3, 2},
    {3, 2, 2, 3},
    {3, 2, 3, 2},
    {3, 2, 3, 2}
};

int rotation_count[8] = {
    0, 2, 1, 2, 2, 4, 4, 4
};

int can_place(int start, int p, int r) {
    int w = width[p][r];
    int min_height = h[start];

    for (int i = 0; i < w; i++) {
        if (h[start + i] < min_height) {
            min_height = h[start + i];
        }
    }

    for (int i = 0; i < w; i++) {
        if (h[start + i] - min_height != patterns[p][r][i]) {
            return 0;
        }
    }

    return 1;
}

int main(void) {
    scanf("%d %d", &C, &P);

    for (int i = 0; i < C; i++) {
        scanf("%d", &h[i]);
    }

    int answer = 0;

    for (int r = 0; r < rotation_count[P]; r++) {
        int w = width[P][r];

        for (int start = 0; start + w <= C; start++) {
            if (can_place(start, P, r)) {
                answer++;
            }
        }
    }

    printf("%d\n", answer);

    return 0;
}