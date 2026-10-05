#include <bits/stdc++.h>
using namespace std;

using ll = long long;
struct Edge{
    int u, v;
    ll w;
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K, S, T;
    cin >> N >> M >> K >> S >> T;
    vector<vector<Edge>> edgesByColor(K+1);

    for(int i=0; i<M;i++){
        int u, v, c;
        ll w;
        cin>>u>>v>>w>>c;
        edgesByColor[c].push_back({u, v, w});
    }
    const ll INF = (1LL << 62);
    vector<ll> dist(N+1, INF);
    dist[S]=0;
    
    vector<int> id(N+1, -1);
    
    for(int color = 1; color <=K; color++){
       if(edgesByColor[color].empty()) continue;
       vector<int> vertices;
       for(auto &e : edgesByColor[color]){
           if (id[e.u]==-1){
               id[e.u]= vertices.size();
               vertices.push_back(e.u);
           }
           if (id[e.v]==-1){
               id[e.v]=vertices.size();
               vertices.push_back(e.v);
           }
       }
       int sz = vertices.size();
       vector<vector<pair<int, ll>>> adj(sz);
       for(auto &e : edgesByColor[color]){
           int a = id[e.u];
           int b = id[e.v];
           adj[a].push_back({b, e.w});
           adj[b].push_back({a, e.w});

       }
       vector<ll> tempDist(sz, INF);
       priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
       for (int i =0;i<sz; i++){
           int v= vertices[i];
           tempDist[i]=dist[v];
           if(dist[v]!=INF){
               pq.push({dist[v], i});

           }
        }
        while (!pq.empty()){
            auto [curDist, u]=pq.top();
            pq.pop();
            if(curDist!=tempDist[u]) continue;
            for(auto [v, w]: adj[u]){
                if(tempDist[v]>curDist+w){
                    tempDist[v]=curDist+w;
                    pq.push({tempDist[v], v});
                }
            }
        }
        for(int i=0; i<sz; i++){
             int v = vertices[i];
             dist[v]=min(dist[v], tempDist[i]);
        }
        for(int v: vertices){
            id[v]=-1;

        }
                  
    }
    if(dist[T]==INF) cout << -1 <<'\n';
    else cout << dist[T] << '\n';

    return 0;
}
