/*LeetCode 1197 — Minimum Knight Moves를 백준식 문제로 정리

LeetCode 문제는 원래 함수형 문제지만, 백준식으로 바꾸면 다음처럼 만들 수 있다.

문제: 무한 나이트 이동

무한히 넓은 2차원 체스판이 있다.

나이트는 처음에 (0, 0)에 있다.
나이트는 체스의 나이트처럼 한 번에 다음 8방향 중 하나로 이동할 수 있다.

(+1, +2), (+1, -2)
(-1, +2), (-1, -2)
(+2, +1), (+2, -1)
(-2, +1), (-2, -1)

목표 좌표 (x, y)가 주어질 때,
나이트가 (0, 0)에서 (x, y)까지 이동하는 데 필요한 최소 이동 횟수를 출력하라.

입력

첫째 줄에 테스트 케이스 개수 T가 주어진다.

그다음 줄부터 T개의 줄에 걸쳐 목표 좌표 x y가 주어진다.

T
x1 y1
x2 y2
...
xT yT
출력

각 테스트 케이스마다 최소 이동 횟수를 한 줄에 하나씩 출력한다.

제한
1 ≤ T ≤ 100000
-1,000,000,000 ≤ x, y ≤ 1,000,000,000

무한 평면이므로 좌표가 음수일 수도 있다.

예제 입력
6
0 0
2 1
1 0
2 2
5 5
7 7
예제 출력
0
1
3
4
4
6
핵심 풀이

일반적인 체스판 최단거리 문제는 BFS로 푼다.

예를 들어 백준 7562, 18404 같은 문제는 체스판 크기가 정해져 있으므로 BFS가 적합하다.

하지만 이 문제는 무한 평면이다.

좌표가 1,000,000,000까지 가능

하므로 배열을 만들 수도 없고, BFS를 하면 너무 느리다.

그래서 수학적 성질을 이용한다.
*/
#include <stdio.h>

long long abs_ll(long long n) {
    if (n < 0) {
        return -n;
    }
    return n;
}

long long max_ll(long long a, long long b) {
    if (a > b) {
        return a;
    }
    return b;
}

long long minKnightMoves(long long x, long long y) {
    x = abs_ll(x);
    y = abs_ll(y);

    if (x < y) {
        long long temp = x;
        x = y;
        y = temp;
    }

    if (x == 0 && y == 0) {
        return 0;
    }

    if (x == 1 && y == 0) {
        return 3;
    }

    if (x == 2 && y == 2) {
        return 4;
    }

    long long a = (x + 1) / 2;
    long long b = (x + y + 2) / 3;

    long long move = max_ll(a, b);

    if ((move + x + y) % 2 != 0) {
        move++;
    }

    return move;
}

int main(void) {
    int T;
    scanf("%d", &T);

    while (T--) {
        long long x, y;
        scanf("%lld %lld", &x, &y);

        printf("%lld\n", minKnightMoves(x, y));
    }

    return 0;
}