
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using State = tuple<ll, int, int>;
// {cost, cur, mask}

const ll INF = (1LL << 60);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<vector<int>> W(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> W[i][j];
        }
    }

    int FULL = (1 << N) - 1;

    // dist[mask][cur]:
    // mask의 도시들을 방문하고 cur에 도착한 최소 비용
    vector<vector<ll>> dist(
        1 << N, vector<ll>(N, INF)
    );

    priority_queue<
        State,
        vector<State>,
        greater<State>
    > pq;

    // 0번 도시에서 출발
    dist[1][0] = 0;
    pq.push({0, 0, 1});

    while (!pq.empty()) {
        auto [cost, cur, mask] = pq.top();
        pq.pop();

        // 이미 더 짧은 경로가 발견된 경우
        if (cost > dist[mask][cur])
            continue;

        // 모든 도시를 방문한 경우
        if (mask == FULL) {
            if (W[cur][0] != 0) {
                cout << cost + W[cur][0] << '\n';
                return 0;
            }
            continue;
        }

        // 다음 도시 탐색
        for (int next = 0; next < N; next++) {

            // 이미 방문한 도시
            if (mask & (1 << next))
                continue;

            // 연결되지 않은 도시
            if (W[cur][next] == 0)
                continue;

            int nextMask = mask | (1 << next);
            ll nextCost = cost + W[cur][next];

            if (nextCost < dist[nextMask][next]) {
                dist[nextMask][next] = nextCost;

                pq.push({
                    nextCost,
                    next,
                    nextMask
                });
            }
        }
    }

    // 모든 도시를 방문하고 복귀할 수 없는 경우
    cout << -1 << '\n';

    return 0;
}
