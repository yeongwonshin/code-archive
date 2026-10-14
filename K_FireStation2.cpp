#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int to;
    long long w;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<vector<Edge>> graph(N+1);

    for (int i = 0; i < N - 1; ++i) {
        int U, V;
        long long W;
        cin >> U >> V >> W;
        graph[U].push_back({V, W});
        graph[V].push_back({U, W});

    }
    if(N==1){
        cout<<0<<'\n';
        return 0;
    }
    vector<int> parent(N+1, 0);
    vector<long long> parentWeight(N+1, 0);
    vector<int> order;
    order.reserve(N);

    stack<int> st;
    st.push(1);
    parent[1]=-1;

    while(!st.empty()){
        int u = st.top();
        st.pop();
        order.push_back(u);
        for(auto &e: graph[u]){
            int v= e.to;
            if(v==parent[u])continue;
//트리는 무방향 그래프이므로 자식에서 부모로 다시 이동하는 것을 방지하기 위함.
            parent[v]=u;
            parentWeight[v]=e.w;
            st.push(v);
        }
    }
    vector<long long> downHeight(N+1, 0);
    vector<long long> downDiameter(N+1, 0);
    for(int idx = N-1;idx>=0;idx--){
        int u = order[idx];
        long long firstHeight=0;
        long long secondHeight=0;
        long long bestDiameter=0;

        for(auto &e: graph[u]){
            int v = e.to;
            if(parent[v]!=u) continue;

            bestDiameter=max(bestDiameter, downDiameter[v]);
            long long h = e.w + downHeight[v];
            if(h>=firstHeight){
                secondHeight = firstHeight;
                firstHeight = h;

            }
            else if (h>secondHeight) secondHeight= h;

        }
        downHeight[u]=firstHeight;
        downDiameter[u]=max(bestDiameter, firstHeight+secondHeight);
    }
    if (K==1){
        cout<<downDiameter[1]<<'\n';
        return 0;
    }
    vector<long long> upHeight(N+1, 0);
    vector<long long> upDiameter(N+1, 0);
    long long answer = LLONG_MAX;
    const long long NEG = LLONG_MIN / 4;
    for(int u : order){
        array<pair<long long, int>, 3> topHeight;
        for(auto &p: topHeight) p={NEG, -1000000000};
        auto addHeight = [&](long long value, int id){
             pair<long long, int> cur = {value, id};
             
             for(int i=0;i<3;i++){
                 if(cur.first>topHeight[i].first){
                     swap(cur, topHeight[i]);
                 }
             }
        };
        array<pair<long long, int>, 2> topDiameter;
        
        for(auto &p:topDiameter)p={NEG, -1000000000};
        auto addDiameter= [&](long long value, int id){
            pair<long long, int> cur = {value, id};

            for(int i=0;i<2;i++){
                if(cur.first>topDiameter[i].first){
                    swap(cur, topDiameter[i]);
                }
        }
    };
    addHeight(0, 0);
    addDiameter(0, 0);

    if(parent[u]!=-1){
        addHeight(upHeight[u], -1);
        addDiameter(upDiameter[u], -1);
    }
    for(auto &e : graph[u]){
        int v = e.to;
        if(parent[v]!=u) continue;

        addHeight(
            e.w + downHeight[v],
            v
        );
        addDiameter(downDiameter[v], v);
    }
    for(auto &e : graph[u]){
        int v= e.to;
        if(parent[v]!=u)continue;

        long long h1 = NEG;
        long long h2 = NEG;
        
        for(auto [value, id]: topHeight){
            if (id == v)continue;
            if(h1==NEG)h1=value;
            else {
                h2= value;
                break;
            }
        }
        if(h1==NEG) h1=0;

        long long internalDiameter = 0;
        for(auto [value, id]: topDiameter){
            if(id == v)continue;
            internalDiameter = max(0LL, value);
            break;
        }
        long long throughU = 0;

        if(h2!=NEG)throughU= h1+h2;

        upDiameter[v]=max(internalDiameter, throughU);
        upHeight[v]=e.w + h1;

        long long candidate = max(downDiameter[v], upDiameter[v]);
        answer = min(answer, candidate);
    }
    }
    cout<<answer<<'\n';

    return 0;
}
