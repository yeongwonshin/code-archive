

/*문제: 가장자리와 연결되지 않은 단지 세기

N × N 크기의 정사각형 지도가 주어진다.

지도에는 0과 1이 적혀 있다.

1은 집이 있는 칸
0은 집이 없는 칸

집은 상하좌우로 붙어 있을 때만 같은 단지로 본다.
대각선으로 붙어 있는 것은 연결된 것으로 보지 않는다.

단, 이 문제에서는 기존 단지번호붙이기 문제와 다르게 조건이 하나 추가된다.

가장자리에 있는 집과 연결된 단지는 카운트하지 않는다.

즉, 어떤 단지 안의 집 중 하나라도 지도의 가장자리, 즉

첫 번째 행
마지막 행
첫 번째 열
마지막 열

에 닿아 있다면 그 단지는 제외한다.

가장자리와 연결되지 않은 내부 단지만 세고, 각 단지의 집 개수를 오름차순으로 출력하라.

입력 형식

첫째 줄에 정수 N이 주어진다.

둘째 줄부터 N개의 줄에 걸쳐 지도가 주어진다.
각 줄은 길이 N인 문자열이며, 0과 1로만 이루어져 있다.

N
지도 1번째 줄
지도 2번째 줄
...
지도 N번째 줄
출력 형식

첫째 줄에 가장자리와 연결되지 않은 단지의 개수를 출력한다.

그다음 줄부터 각 단지에 속한 집의 개수를 오름차순으로 한 줄에 하나씩 출력한다.

조건
5 ≤ N ≤ 25
예제 입력 1
7
0110100
0110101
1110101
0000111
0100000
0111110
0111000
예제 출력 1
0
예제 1 설명

기존 백준 2667번 단지번호붙이기 문제라면 여러 단지가 존재한다.

하지만 이 문제에서는 가장자리와 연결된 단지를 제외해야 한다.

위 지도에서 존재하는 모든 1 단지는 결국 지도의 가장자리와 연결되어 있다.

따라서 카운트되는 내부 단지는 없다.

그래서 출력은 다음과 같다.

0
예제 입력 2
7
0000000
0111000
0101000
0111000
0000110
0000110
0000000
예제 출력 2
2
4
8
예제 2 설명

지도를 보면 내부에 두 개의 단지가 있다.

첫 번째 단지:

111
101
111

집 개수는 8개이다.

두 번째 단지:

11
11

집 개수는 4개이다.

두 단지 모두 가장자리에 닿아 있지 않으므로 카운트한다.

집 개수를 오름차순으로 출력해야 하므로 다음과 같이 출력한다.

2
4
8
*/
#include <iostream>
#include <cstring>
using namespace std;

int N;
int grid[25][25];
int visited[25][25];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int dfs(int x, int y, bool &touch_edge) {
    visited[x][y] = 1;

    if (x == 0 || x == N - 1 || y == 0 || y == N - 1) {
        touch_edge = true;
    }

    int count = 1;

    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];

        if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
        if (grid[nx][ny] == 0) continue;
        if (visited[nx][ny]) continue;

        /*
            nx, ny가 가장자리인지 여기서 따로 검사할 필요는 없다.

            dfs(nx, ny, touch_edge)가 호출되면
            함수 시작 부분에서

            if (x == 0 || x == N - 1 || y == 0 || y == N - 1)

            로 검사하기 때문이다.
        */
        count += dfs(nx, ny, touch_edge);
    }

    return count;
}

void sort_array(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    string line;

    for (int i = 0; i < N; i++) {
        cin >> line;

        for (int j = 0; j < N; j++) {
            grid[i][j] = line[j] - '0';
        }
    }

    int result[625];
    int complex_count = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == 1 && !visited[i][j]) {
                bool touch_edge = false;

                int house_count = dfs(i, j, touch_edge);

                if (!touch_edge) {
                    result[complex_count++] = house_count;
                }
            }
        }
    }

    sort_array(result, complex_count);

    cout << complex_count << '\n';

    for (int i = 0; i < complex_count; i++) {
        cout << result[i] << '\n';
    }

    return 0;
}