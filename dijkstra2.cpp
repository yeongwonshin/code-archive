/*1. 문제 설명
\(N\)개의 정점과 \(E\)개의 간선으로 이루어진 무방향 가중치 그래프가 주어진다.
1번 정점에서 출발하여 N번 정점까지 이동하되, 반드시 두 정점 \(v_1,v_2\)를 모두 통과해야 한다.
조건은 다음과 같다.
- 모든 간선에는 양의 가중치가 있다.
- 그래프는 무방향이다.
- 특정 정점과 간선을 여러 번 방문해도 된다.
- 두 정점 \(v_1,v_2\)는 반드시 방문해야 한다.
1번 정점에서 N번 정점까지 이동하는 최소 비용을 구하시오.
경로가 존재하지 않는다면 -1을 출력한다.
2. 입력
- 첫 번째 줄: 정점 개수 \(N\), 간선 개수 \(E\)
- 다음 \(E\)개 줄: 두 정점 a, b와 간선 가중치 c
- 마지막 줄: 반드시 방문해야 하는 두 정점 \(v_1,v_2\)
주요 제한 조건:
- \(2\le N\le800\)
- \(0\le E\le200,000\)
- \(1\le c\le1,000\)
3. 입출력 예제
예제 입력
4 6
1 2 3
2 3 3
3 4 1
1 3 5
2 4 5
1 4 4
2 3



예제 출력
7
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using P = pair<ll, int>;

const ll INF = (1LL << 60);

int N, E;
vector<vector<pair<int, int>>> graph;

vector<ll> dijkstra(int start) {
    vector<ll> dist(N + 1, INF);

    priority_queue<P, vector<P>, greater<P>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [cost, cur] = pq.top();
        pq.pop();

        if (cost > dist[cur])
            continue;

        for (auto [next, weight] : graph[cur]) {
            ll newDist = cost + weight;

            if (newDist < dist[next]) {
                dist[next] = newDist;
                pq.push({newDist, next});
            }
        }
    }

    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> E;

    graph.resize(N + 1);

    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        // 무방향 그래프
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    int v1, v2;
    cin >> v1 >> v2;

    // 총 세 번의 다익스트라
    vector<ll> d1 = dijkstra(1);
    vector<ll> dv1 = dijkstra(v1);
    vector<ll> dv2 = dijkstra(v2);

    ll route1 = INF;
    ll route2 = INF;

    // 1 -> v1 -> v2 -> N
    if (d1[v1] != INF &&
        dv1[v2] != INF &&
        dv2[N] != INF) {

        route1 = d1[v1] + dv1[v2] + dv2[N];
    }

    // 1 -> v2 -> v1 -> N
    if (d1[v2] != INF &&
        dv2[v1] != INF &&
        dv1[N] != INF) {

        route2 = d1[v2] + dv2[v1] + dv1[N];
    }

    ll answer = min(route1, route2);

    if (answer == INF)
        cout << -1 << '\n';
    else
        cout << answer << '\n';

    return 0;
}
