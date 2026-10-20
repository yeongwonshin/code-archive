/*1. 문제 설명
\(N\)명의 학생이 각각 1번부터 N번까지 번호가 붙은 마을에 살고 있다.
모든 학생은 \(X\)번 마을에서 열리는 파티에 참석해야 한다.
도로는 단방향이며, 각 도로에는 이동 시간이 정해져 있다.
모든 학생은 다음과 같이 이동한다.
1. 자신의 마을에서 X번 마을까지 이동
2. 파티가 끝난 후 X번 마을에서 자신의 마을까지 이동
각 학생은 두 이동 모두 최단 경로를 사용한다.
왕복 이동 시간이 가장 오래 걸리는 학생의 소요 시간을 출력하시오.
2. 입력
첫 번째 줄에는 다음 세 정수가 주어진다.
N M X


- \(N\): 학생 및 마을 개수 (\(1\le N\le1,000\))
- \(M\): 단방향 도로 개수 (\(1\le M\le10,000\))
- \(X\): 파티가 열리는 마을 번호
다음 \(M\)개 줄에는 도로의 정보가 주어진다.
출발마을 도착마을 이동시간


각 이동 시간은 1 이상 100 이하이며, 모든 학생이 파티에 참석하고 돌아올 수 있는 경우만 주어진다.
3. 입출력 예제
예제 입력
4 8 2
1 2 4
1 3 2
3 2 1
2 4 2
4 1 3
3 4 5
2 1 6
4 3 1



예제 출력
8
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using P = pair<ll, int>;

const ll INF = (1LL << 60);

vector<ll> dijkstra(
    int start,
    const vector<vector<pair<int, int>>>& graph
) {
    int N = (int)graph.size() - 1;

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

    int N, M, X;
    cin >> N >> M >> X;

    vector<vector<pair<int, int>>> graph(N + 1);
    vector<vector<pair<int, int>>> reverseGraph(N + 1);

    for (int i = 0; i < M; i++) {
        int a, b, t;
        cin >> a >> b >> t;

        // 원래 그래프
        graph[a].push_back({b, t});

        // 역방향 그래프
        reverseGraph[b].push_back({a, t});
    }

    // X에서 각 마을로 돌아가는 최단 거리
    vector<ll> go = dijkstra(X, graph);

    // 각 마을에서 X까지 가는 최단 거리
    vector<ll> back = dijkstra(X, reverseGraph);

    ll answer = 0;

    for (int i = 1; i <= N; i++) {
        if (go[i] == INF || back[i] == INF)
            continue;

        ll roundTrip = go[i] + back[i];
        answer = max(answer, roundTrip);
    }

    cout << answer << '\n';

    return 0;
}
