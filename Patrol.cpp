/*1. 문제 설명
크기가 \(N\times N\)인 도시가 있으며, 두 대의 경찰차가 사건을 처리한다.
- 경찰차 1은 처음에 \((1,1)\)에 위치한다.
- 경찰차 2는 처음에 \((N,N)\)에 위치한다.
- 총 \(W\)개의 사건이 순서대로 발생한다.
- 각 사건은 반드시 경찰차 한 대가 처리해야 한다.
- 경찰차는 상하좌우로 이동할 수 있으며, 이동 거리는 맨해튼 거리로 계산한다.
두 경찰차가 모든 사건을 순서대로 처리할 때, 두 경찰차가 이동한 거리의 합을 최소화해야 한다.
또한 각 사건을 어느 경찰차가 처리했는지도 출력해야 한다.
2. 입력과 출력
입력
- 첫 번째 줄: 도시의 크기 \(N\) (\(5\le N\le1000\))
- 두 번째 줄: 사건 개수 \(W\) (\(1\le W\le1000\))
- 다음 \(W\)개 줄: 사건의 위치 \(x,y\)
출력
- 첫 번째 줄: 최소 이동 거리의 합
- 다음 \(W\)개 줄: 각 사건을 처리한 경찰차 번호(1 또는 2)
예제 입력
6
3
3 5
5 5
2 3


예제 출력
9
2
2
1
*/

#include <bits/stdc++.h>
using namespace std;

int N, W;// 도시 크기, 사건 개수
vector<pair<int, int>> events;//사건이 발생하는 좌표
vector<vector<int>> dp;
//dp[a][b]:a번째 사건까지 경찰차 1이 처리하고, b번째 사건까지 경찰차 2가 처리했을 때, 최소 이동 거리
vector<vector<int>> choice;
//현재 상태에서 다음 사건을 경찰차 1이 처리할지, 경찰차 2가 처리할지 선택

int dist(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

int solve(int a, int b) {
    int next = max(a, b) + 1;
//a: 경찰차 1이 처리한 사건의 번호, b: 경찰차 2가 처리한 사건의 번호, next: 다음 사건 번호
    // 모든 사건을 처리한 경우
    if (next > W)
        return 0;

    int &ret = dp[a][b];

    if (ret != -1)
        return ret;

    // 경찰차 1의 현재 위치
    auto [x1, y1] = (a == 0)
        ? make_pair(1, 1)
        : events[a];

    // 경찰차 2의 현재 위치
    auto [x2, y2] = (b == 0)
        ? make_pair(N, N)
        : events[b];

    auto [nx, ny] = events[next];

    // 경찰차 1이 다음 사건 처리
    int cost1 = dist(x1, y1, nx, ny)
              + solve(next, b);

    // 경찰차 2가 다음 사건 처리
    int cost2 = dist(x2, y2, nx, ny)
              + solve(a, next);

    if (cost1 <= cost2) {
        choice[a][b] = 1;
        ret = cost1;
    } else {
        choice[a][b] = 2;
        ret = cost2;
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> W;

    events.resize(W + 1);

    for (int i = 1; i <= W; i++) {
        cin >> events[i].first
            >> events[i].second;
    }

    dp.assign(W + 1, vector<int>(W + 1, -1));
    choice.assign(W + 1, vector<int>(W + 1, 0));

    cout << solve(0, 0) << '\n';

    // 최적 경로 복원
    int a = 0, b = 0;

    for (int next = 1; next <= W; next++) {
        int car = choice[a][b];
        cout << car << '\n';

        if (car == 1)
            a = next;
        else
            b = next;
    }

    return 0;
}
