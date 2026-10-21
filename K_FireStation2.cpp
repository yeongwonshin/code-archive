
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Edge {
    int to;
    ll w;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<vector<Edge>> graph(N + 1);

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;

        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    vector<ll> dist;
    vector<int> parent, order;

    // DFS: 가장 먼 정점 찾기 + 부모와 방문 순서 기록
    auto dfs = [&](int start) {
        dist.assign(N + 1, -1);
        parent.assign(N + 1, -1);
        order.clear();

        stack<int> st;
        st.push(start);
        dist[start] = 0;

        int far = start;

        while (!st.empty()) {
            int u = st.top();
            st.pop();

            order.push_back(u);

            if (dist[u] > dist[far])
                far = u;

            for (auto [v, w] : graph[u]) {
                if (dist[v] != -1) continue;

                dist[v] = dist[u] + w;
                parent[v] = u;
                st.push(v);
            }
        }
        return far;
    };

    // 전체 트리의 지름 찾기
    int A = dfs(1);
    int B = dfs(A);

    ll D = dist[B];

    if (K == 1 || D == 0) {
        cout << (K == 1 ? D : 0) << '\n';
        return 0;
    }

    // 지름 경로 A -> B 복원
    vector<int> path;

    for (int u = B; u != -1; u = parent[u])
        path.push_back(u);

    reverse(path.begin(), path.end());

    int M = path.size();

    // 각 정점이 지름 경로의 어느 정점에 붙어 있는지 기록
    vector<int> group(N + 1, -1);

    for (int i = 0; i < M; i++)
        group[path[i]] = i;

    vector<ll> left(M, 0), right(M, 0);

    for (int u : order) {
        if (group[u] == -1)//그루핑이 안 되어있는 경우
            group[u] = group[parent[u]];//부모의 그룹 넘버를 자식에게 물려줌.

        int i = group[u];

        ll side = dist[u] - dist[path[i]];
//side는 지름 경로에서 벗어나 가지로 들어간 거리
        left[i] = max(left[i], dist[u]);
//left[i]는 group i에 속한 정점들 중 A에서 가장 먼 정점까지의 거리
        right[i] = max(
            right[i],
            D - dist[path[i]] + side
        );
    }

    // A쪽의 누적 최대 거리
    for (int i = 1; i < M; i++)
        left[i] = max(left[i], left[i - 1]);

    // B쪽의 누적 최대 거리
    for (int i = M - 2; i >= 0; i--)
        right[i] = max(right[i], right[i + 1]);

    ll answer = LLONG_MAX;

    // 지름 경로 위의 간선을 하나씩 제거
    for (int i = 0; i + 1 < M; i++) {
        ll candidate = max(left[i], right[i + 1]);
        answer = min(answer, candidate);
    }

    cout << answer << '\n';
}
