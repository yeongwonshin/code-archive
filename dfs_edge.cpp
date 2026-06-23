/*
문제: 갇힌 섬 세기

N × M 크기의 지도가 주어진다.

지도에는 다음 두 종류의 칸이 있다.

1 : 땅
0 : 바다

땅은 상하좌우로 인접해 있으면 같은 섬에 속한다.
대각선으로 닿은 땅은 같은 섬이 아니다.

이때, 지도 가장자리에 닿아 있지 않은 섬만 “갇힌 섬”이라고 부른다.

지도 가장자리는 다음 위치를 말한다.

첫 번째 행
마지막 행
첫 번째 열
마지막 열

즉, 어떤 섬에 속한 땅 중 하나라도 가장자리에 있으면 그 섬은 갇힌 섬이 아니다.

갇힌 섬의 개수와, 각 갇힌 섬의 넓이를 오름차순으로 출력하라.

입력

첫째 줄에 정수 N, M이 주어진다.

3 ≤ N, M ≤ 100

둘째 줄부터 N개의 줄에 걸쳐 지도가 주어진다.

각 줄은 길이 M의 문자열이며, 0과 1로만 이루어져 있다.

출력

첫째 줄에 갇힌 섬의 개수를 출력한다.

그다음 줄부터 각 갇힌 섬의 넓이를 오름차순으로 한 줄에 하나씩 출력한다.

갇힌 섬이 하나도 없다면 첫째 줄에 0만 출력한다.

예제 입력 1
7 8
00000000
01100100
01100100
00000000
01011110
01000010
00000000
예제 출력 1
2
4
6
예제 설명 1

첫 번째 갇힌 섬:

11
11

넓이 4

두 번째 갇힌 섬은 가운데 아래쪽에 있으며 넓이 6이다.

두 섬 모두 지도 가장자리에 닿아 있지 않으므로 카운트한다.

예제 입력 2
5 5
11111
10001
10101
10001
11111
예제 출력 2
1
1
예제 설명 2

가장자리의 1들은 모두 하나의 큰 섬이고, 가장자리에 닿아 있으므로 제외된다.

가운데 (2, 2) 위치의 1만 독립된 섬이고, 가장자리에 닿아 있지 않으므로 갇힌 섬이다.

넓이는 1이다.*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;    

int board[100][100];
bool visited[100][100];
int n, m;
bool flag = true;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int dfs(int x, int y) {
    int area = 1;
    
    visited[x][y] = true;
    if(x == 0 || x == n - 1 || y == 0 || y == m - 1) {
        flag = false;
    }

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
            continue;
        }

        if (board[nx][ny] == 1 && !visited[nx][ny]) {
            area += dfs(nx, ny);
        }
    }

    return area;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < m; j++) {
            board[i][j] = s[j] - '0';
        }
    }

    int count = 0;
    int areas[10000];
    int idx = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 1 && !visited[i][j]) {
                flag = true;
 //flag초기화안해주면 dfs돌면서 flag가 false로 바뀌고 그 이후로는 계속 false로 남아있어서 모든 섬이 갇힌 섬이 아닌걸로 나옴
                int area = dfs(i, j);

                if (flag) {
                    areas[idx++] = area;
                    count++;
                }
            }
        }
    }

    cout << count << '\n';
    sort(areas, areas + idx);

    for (int i = 0; i < idx; i++) {
        cout << areas[i] << '\n';
    }

    return 0;
}