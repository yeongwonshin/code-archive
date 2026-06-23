/*
이 코드는 백준 1987번 — 알파벳 문제에 해당한다.

문제 설명

세로 R칸, 가로 C칸으로 된 보드가 있다.

각 칸에는 알파벳 대문자 A부터 Z 중 하나가 적혀 있다.

말은 처음에 왼쪽 위 칸, 즉 (0, 0) 위치에서 시작한다.

말은 한 번에 상하좌우 네 방향 중 하나로 이동할 수 있다.

위    : x - 1, y
아래  : x + 1, y
왼쪽  : x, y - 1
오른쪽: x, y + 1

단, 이동할 때 중요한 조건이 있다.

지금까지 지나온 칸에 적힌 알파벳과 같은 알파벳이 있는 칸으로는 이동할 수 없다.

즉, 경로 안에서 같은 알파벳이 두 번 나오면 안 된다.

목표는 말이 최대한 많이 이동했을 때, 몇 칸까지 지나갈 수 있는지 구하는 것이다.

입력 형식

첫째 줄에 보드의 세로 길이 R과 가로 길이 C가 주어진다.

R C

그다음 R개의 줄에 걸쳐 보드 정보가 주어진다.

각 줄은 길이 C인 대문자 문자열이다.

제한 조건
1 ≤ R, C ≤ 20

보드에는 알파벳 대문자만 주어진다.

출력 형식

말이 지나갈 수 있는 최대 칸 수를 출력한다.

예제 입력 1
2 4
CAAB
ADCB
예제 출력 1
3*/
#include <iostream>
#include <string>
using namespace std;

int R, C;
string board[21];
int used[26];
int answer = 0;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(int x, int y, int depth) {
    if (depth > answer) {
        answer = depth;
    }

    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];

        if (nx < 0 || nx >= R || ny < 0 || ny >= C) {
            continue;
        }

        int alpha = board[nx][ny] - 'A';

        if (!used[alpha]) {
            used[alpha] = 1;
            dfs(nx, ny, depth + 1);
            used[alpha] = 0;/*if문이나 for문 밖에다 적으면 안됨.
             !used일 때에만 백트래킹이 되어야하기 때문
        */
            }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        cin >> board[i];
    }

    used[board[0][0] - 'A'] = 1;
    dfs(0, 0, 1);

    cout << answer << '\n';

    return 0;
}