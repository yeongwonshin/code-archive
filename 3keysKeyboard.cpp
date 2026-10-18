
/*
문제: 3 Keys Keyboard
처음 화면에는 문자 'A'가 정확히 하나만 입력되어 있다.
사용할 수 있는 연산은 다음 세 가지뿐이다.
1. Copy All (전체 복사): 현재 화면에 있는 모든 문자를 클립보드에 복사한다.
2. Paste (붙여넣기): 클립보드에 복사된 문자열을 화면 끝에 붙여넣는다.
3. Delete (삭제): 화면 맨 끝에 있는 문자 'A' 하나를 삭제한다.
각 연산은 정확히 1회의 조작으로 계산한다.
목표
화면에 정확히 N개의 'A'를 만들기 위해 필요한 최소 연산 횟수를 구하시오.
*/
#include <bits/stdc++.h>
using namespace std;

int minSteps(int N) {
    if (N == 1) return 0;

    int LIMIT = 2 * N;

    vector<vector<int>> dist(
        LIMIT + 1, vector<int>(LIMIT + 1, -1)
    );

    queue<pair<int, int>> q;

    q.push({1, 0});
    dist[1][0] = 0;

    while (!q.empty()) {
        auto [screen, clipboard] = q.front();
        q.pop();

        int steps = dist[screen][clipboard];

        if (screen == N)
            return steps;

        // 1. Copy All
        if (screen > 0 &&
            dist[screen][screen] == -1) {

            dist[screen][screen] = steps + 1;
            q.push({screen, screen});
        }

        // 2. Paste
        if (clipboard > 0 &&
            screen + clipboard <= LIMIT &&
            dist[screen + clipboard][clipboard] == -1) {

            dist[screen + clipboard][clipboard] = steps + 1;
            q.push({screen + clipboard, clipboard});
        }

        // 3. Delete
        if (screen > 0 &&
            dist[screen - 1][clipboard] == -1) {

            dist[screen - 1][clipboard] = steps + 1;
            q.push({screen - 1, clipboard});
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    cout << minSteps(N) << '\n';

    return 0;
}
