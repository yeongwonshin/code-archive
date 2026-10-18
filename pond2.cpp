/*원형으로 배치된 N개의 연못이 있고, 번호가 시계방향으로 1부터 N까지 부여됩니다.
R마리의 개구리가 서로 다른 연못에서 출발합니다. 각 개구리는 1분마다 시계방향으로 점프하며, 자신의 K개 점프 패턴을 반복합니다.
첫 번째 개구리는 처음부터 전염병에 감염되어 있습니다. 감염된 개구리와 건강한 개구리가 같은 시각에 같은 연못에 도착하면 병이 전염됩니다.
목표: 최종적으로 감염되는 개구리의 수와 마지막 감염이 발생하는 시각을 구합니다.
예제 입력
5 2 3
2 4
1 2 1
1 1 1


예제 출력
2 5
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = (1LL << 62);

// 확장 유클리드 알고리즘
ll extgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    ll x1, y1;
    ll g = extgcd(b, a % b, x1, y1);

    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    int R, K;

    while (cin >> N >> R >> K) {
        vector<ll> B(R), delta(R);
        vector<vector<ll>> pos(R, vector<ll>(K));

        for (int i = 0; i < R; i++) {
            cin >> B[i];
            B[i]--;
        }

        // 각 개구리의 주기 내 위치와
        // 한 주기 동안의 이동량 계산
        for (int i = 0; i < R; i++) {
            ll cur = B[i];

            for (int s = 0; s < K; s++) {
                pos[i][s] = cur;

                ll step;
                cin >> step;
                cur = (cur + step) % N;
            }

            delta[i] = (cur - B[i] + N) % N;
        }

        vector<ll> dist(R, INF);
        vector<bool> visited(R, false);

        dist[0] = 0;

        // 시간에 의존하는 최단 경로
        for (int rep = 0; rep < R; rep++) {
            int u = -1;

            for (int i = 0; i < R; i++) {
                if (!visited[i] &&
                    (u == -1 || dist[i] < dist[u])) {
                    u = i;
                }
            }

            if (u == -1 || dist[u] == INF)
                break;

            visited[u] = true;
            ll currentTime = dist[u];

            for (int v = 0; v < R; v++) {
                if (visited[v]) continue;

                ll a = (delta[u] - delta[v] + N) % N;
                ll g = gcd(a, N);
                ll period = N / g;

                ll inv = 0;

                if (period > 1) {
                    ll x, y;
                    extgcd(a / g, period, x, y);
                    inv = (x % period + period) % period;
                }

                ll cycle = period * K;
                ll nextMeet = INF;

                // K개의 각 시간 위상에 대해
                // 두 개구리의 만남 계산
                for (int s = 0; s < K; s++) {
                    ll rhs =
                        (pos[v][s] - pos[u][s] + N) % N;

                    if (rhs % g != 0)
                        continue;

                    ll q0 = 0;

                    if (period > 1) {
                        q0 = ((rhs / g) * inv) % period;
                    }

                    ll meet = q0 * K + s;

                    if (meet < currentTime) {
                        ll diff = currentTime - meet;
                        ll repeat = (diff + cycle - 1) / cycle;
                        meet += repeat * cycle;
                    }

                    nextMeet = min(nextMeet, meet);
                }

                dist[v] = min(dist[v], nextMeet);
            }
        }

        int infected = 0;
        ll lastTime = 0;

        for (ll t : dist) {
            if (t != INF) {
                infected++;
                lastTime = max(lastTime, t);
            }
        }

        cout << infected << ' ' << lastTime << '\n';
    }

    return 0;
}

