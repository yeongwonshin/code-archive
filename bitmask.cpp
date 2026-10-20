/*1. 문제 설명
\(N\)개의 도시가 있고, 도시 간 이동 비용이 주어진다.
한 외판원이 특정 도시에서 출발하여 다음 조건을 만족하는 경로를 찾아야 한다.
- 모든 도시를 정확히 한 번씩 방문한다.
- 마지막에는 출발 도시로 돌아온다.
- 도시 사이에 이동할 수 없는 경로가 존재할 수 있다.
- 도시 A에서 B로 가는 비용과 B에서 A로 가는 비용은 다를 수 있다.
모든 도시를 순회한 뒤 출발점으로 돌아오는 최소 이동 비용을 출력하시오.
2. 입력과 출력
입력
- 첫 번째 줄: 도시 개수 \(N\) (\(2\le N\le16\))
- 다음 \(N\)개 줄: 도시 간 이동 비용 행렬 \(W\)
- \(W[i][j]=0\)이면 i에서 j로 직접 이동할 수 없다.
출력
모든 도시를 순회하는 최소 비용을 출력한다.
예제 입력
4
0 10 15 20
5 0 9 10
6 13 0 12
8 8 9 0


예제 출력
35
*/

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int N;
vector<vector<int>> W;
vector<vector<int>> dp;

int tsp(int cur, int mask) {
    // 모든 도시를 방문한 경우
    if (mask == (1 << N) - 1) {
        // 출발 도시(0번)로 돌아갈 수 있는가?
        if (W[cur][0] != 0)
            return W[cur][0];

        return INF;
    }

    int &ret = dp[cur][mask];

    if (ret != -1)
        return ret;

    ret = INF;

    for (int next = 0; next < N; next++) {
        // 이미 방문한 도시라면 건너뜀
        if (mask & (1 << next))
            continue;

        // 이동할 수 없는 경로
        if (W[cur][next] == 0)
            continue;

        int nextMask = mask | (1 << next);

        int cost = W[cur][next]
                 + tsp(next, nextMask);

        ret = min(ret, cost);
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    W.assign(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> W[i][j];
        }
    }

    dp.assign(N, vector<int>(1 << N, -1));

    // 0번 도시에서 출발
    // mask = 1: 0번 도시를 방문한 상태
    cout << tsp(0, 1) << '\n';

    return 0;
}

