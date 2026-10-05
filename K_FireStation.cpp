#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to;
    long double w;
};

int N, K;
vector<vector<Edge>> graph;

// banned edge를 사용하지 않고
// start에서 가장 멀리 있는 정점을 찾는다.
pair<int, long double> farthest(
    int start,
    int banU = -1,
    int banV = -1,
    vector<int>* parentResult = nullptr
) {
    vector<long double> dist(N + 1, -1);
    vector<int> parent(N + 1, -1);

    stack<int> st;

    dist[start] = 0;
    st.push(start);

    while (!st.empty()) {
        int cur = st.top();
        st.pop();

        for (auto &e : graph[cur]) {
            int next = e.to;

            // 제거된 edge라면 지나가지 않는다.
            if ((cur == banU && next == banV) ||
                (cur == banV && next == banU))
                continue;

            if (dist[next] != -1)
                continue;

            dist[next] = dist[cur] + e.w;
            parent[next] = cur;

            st.push(next);
        }
    }

    int farNode = start;
    long double farDist = 0;

    for (int i = 1; i <= N; i++) {
        if (dist[i] > farDist) {
            farDist = dist[i];
            farNode = i;
        }
    }

    if (parentResult != nullptr)
        *parentResult = parent;

    return {farNode, farDist};
}


// 하나의 component의 diameter 계산
long double getDiameter(
    int start,
    int banU = -1,
    int banV = -1
) {
    auto first = farthest(start, banU, banV);

    int A = first.first;

    auto second = farthest(A, banU, banV);

    return second.second;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;

    graph.resize(N + 1);

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        long double w;

        cin >> u >> v >> w;

        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }


    // ------------------------------------
    // 1. 전체 tree의 diameter 구하기
    // ------------------------------------

    auto first = farthest(1);

    int A = first.first;

    vector<int> parent;

    auto second = farthest(A, -1, -1, &parent);

    int B = second.first;
    long double D = second.second;


    // ------------------------------------
    // K = 1
    // ------------------------------------

    if (K == 1) {

        cout << fixed << setprecision(6);

        cout << (D / 2.0L) << '\n';

        return 0;
    }


    // ------------------------------------
    // K = 2
    // ------------------------------------

    // A-B diameter path 복원
    vector<int> path;

    int cur = B;

    while (cur != -1) {
        path.push_back(cur);

        if (cur == A)
            break;

        cur = parent[cur];
    }

    reverse(path.begin(), path.end());


    long double best = numeric_limits<long double>::max();

    int bestU = -1;
    int bestV = -1;


    // diameter path 위의 edge만 확인
    for (int i = 0; i + 1 < (int)path.size(); i++) {

        int u = path[i];
        int v = path[i + 1];

        // edge (u,v)를 제거했다고 가정

        long double D1 = getDiameter(u, u, v);
        long double D2 = getDiameter(v, u, v);

        long double candidate =
            max(D1, D2) / 2.0L;

        if (candidate < best) {
            best = candidate;

            bestU = u;
            bestV = v;
        }
    }


    cout << fixed << setprecision(6);

    cout << best << '\n';

    return 0;
}