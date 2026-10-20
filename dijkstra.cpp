/*
1. 문제 설명
\(N\)개의 도시와 \(M\)개의 버스 노선이 존재한다.
각 버스 노선에는 출발 도시, 도착 도시, 이동 비용이 주어진다.
출발 도시 \(S\)에서 도착 도시 \(E\)로 이동할 때 다음 정보를 구하시오.
- 이동하는 데 필요한 최소 비용
- 최소 비용으로 이동할 때 방문하는 도시의 개수
- 해당 경로에서 방문하는 도시의 순서
버스는 단방향으로 운행하며, 같은 두 도시 사이에 여러 버스 노선이 존재할 수 있다.
2. 입력
첫 번째 줄에는 도시의 개수 \(N\)이 주어진다.
두 번째 줄에는 버스 노선의 개수 \(M\)이 주어진다.
다음 \(M\)개 줄에는 각 버스의 정보가 주어진다.
출발도시 도착도시 비용


마지막 줄에는 출발 도시 \(S\)와 도착 도시 \(E\)가 주어진다.
주요 제한 조건:
- \(1\le N\le1,000\)
- \(1\le M\le100,000\)
- 버스 비용은 1 이상 100,000 이하
- 출발 도시에서 도착 도시로 가는 경로가 존재한다.
3. 출력
첫 번째 줄에 최소 비용, 두 번째 줄에 방문한 도시 개수, 세 번째 줄에 경로의 도시 번호를 순서대로 출력한다.
예제 입력
5
7
1 2 2
1 3 7
2 3 2
2 4 5
3 4 1
4 5 2
3 5 8
1 5



예제 출력
7
5
1 2 3 4 5
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using P = pair<ll, int>;

const ll INF = (1LL << 60);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<pair<int, int>>> graph(N + 1);

    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        graph[u].push_back({v, w});
    }

    int S, E;
    cin >> S >> E;

    vector<ll> dist(N + 1, INF);
    vector<int> parent(N + 1, -1);

    priority_queue<P, vector<P>, greater<P>> pq;

    dist[S] = 0;
    pq.push({0, S});

    while (!pq.empty()) {
        auto [cost, cur] = pq.top();
        pq.pop();

        if (cost > dist[cur])
            continue;

        for (auto [next, weight] : graph[cur]) {
            ll newDist = cost + weight;

            if (newDist < dist[next]) {
                dist[next] = newDist;
                parent[next] = cur;

                pq.push({newDist, next});
            }
        }
    }

    // 최단 경로 복원
    vector<int> path;

    for (int cur = E; cur != -1; cur = parent[cur]) {
        path.push_back(cur);
    }

    reverse(path.begin(), path.end());

    cout << dist[E] << '\n';
    cout << path.size() << '\n';

    for (int city : path) {
        cout << city << ' ';
    }
    cout << '\n';

    return 0;
}
