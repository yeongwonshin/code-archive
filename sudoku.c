/*

4. 스도쿠

BOJ 2580과 같은 스도쿠 풀이 문제입니다. 스도쿠는 각 행, 각 열, 각 3×3 박스에 1~9가 한 번씩 들어가야 하며, 빈칸을 채우는 대표적인 백트래킹 문제입니다.

문제

9 × 9 스도쿠 판이 주어진다.
빈칸은 0으로 주어진다.

스도쿠 규칙에 맞게 모든 빈칸을 채운 뒤 완성된 스도쿠 판을 출력하라.

스도쿠 규칙은 다음과 같다.

각 행에는 1부터 9까지의 숫자가 한 번씩만 나와야 한다.
각 열에는 1부터 9까지의 숫자가 한 번씩만 나와야 한다.
각 3 × 3 박스에는 1부터 9까지의 숫자가 한 번씩만 나와야 한다.
입력
9개의 줄에 걸쳐 스도쿠 판이 주어진다.
출력

완성된 스도쿠 판을 출력한다.

예제 입력
0 3 5 4 6 9 2 7 8
7 8 2 1 0 5 6 0 9
0 6 0 2 7 8 1 3 5
3 2 1 0 4 6 8 9 7
8 0 4 9 1 3 5 0 6
5 9 6 8 2 0 4 1 3
9 1 7 6 5 2 0 8 0
6 0 3 7 0 1 9 5 2
2 5 8 3 9 4 7 6 0
예제 출력
1 3 5 4 6 9 2 7 8
7 8 2 1 3 5 6 4 9
4 6 9 2 7 8 1 3 5
3 2 1 5 4 6 8 9 7
8 7 4 9 1 3 5 2 6
5 9 6 8 2 7 4 1 3
9 1 7 6 5 2 3 8 4
6 4 3 7 8 1 9 5 2
2 5 8 3 9 4 7 6 1*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int board[9][9];

int row_used[9][10];
int col_used[9][10];
int box_used[9][10];

int empty_r[81];
int empty_c[81];
int empty_count = 0;

int get_box_index(int r, int c) {
    return (r / 3) * 3 + (c / 3);
}

void print_board(void) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d", board[i][j]);
            if (j < 8) printf(" ");
        }
        printf("\n");
    }
}

void solve(int idx) {
    if (idx == empty_count) {
        print_board();
        exit(0);
    }

    int r = empty_r[idx];
    int c = empty_c[idx];
    int b = get_box_index(r, c);

    for (int num = 1; num <= 9; num++) {
        if (!row_used[r][num] && !col_used[c][num] && !box_used[b][num]) {
            board[r][c] = num;
            row_used[r][num] = 1;
            col_used[c][num] = 1;
            box_used[b][num] = 1;

            solve(idx + 1);

            board[r][c] = 0;
            row_used[r][num] = 0;
            col_used[c][num] = 0;
            box_used[b][num] = 0;
        }
    }
}

int main(void) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%d", &board[i][j]);

            if (board[i][j] == 0) {
                empty_r[empty_count] = i;
                empty_c[empty_count] = j;
                empty_count++;
            } else {
                int num = board[i][j];
                int b = get_box_index(i, j);

                row_used[i][num] = 1;
                col_used[j][num] = 1;
                box_used[b][num] = 1;
            }
        }
    }

    solve(0);

    return 0;
}
