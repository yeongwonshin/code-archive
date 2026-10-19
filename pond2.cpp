/*# 문제: 전염병에 걸린 개구리

## 문제 설명

원형으로 연결된 **N개의 연못**이 있습니다. 각 연못에는 시계방향으로 1번부터 N번까지 번호가 붙어 있습니다.

N번 연못에서 시계방향으로 이동하면 다시 1번 연못으로 돌아옵니다.

이 연못들에는 **R마리의 개구리**가 살고 있습니다. 개구리들은 각각 서로 다른 연못에서 출발하며, 1분마다 시계방향으로 점프합니다.

각 개구리는 자신만의 **K개로 이루어진 점프 패턴**을 가지고 있으며, 이 패턴을 무한히 반복합니다.

예를 들어 어떤 개구리의 점프 패턴이 `[1, 2, 3]`이라면 다음과 같이 이동합니다.

- 1분 후: 시계방향으로 1칸 이동
- 2분 후: 시계방향으로 2칸 이동
- 3분 후: 시계방향으로 3칸 이동
- 4분 후: 다시 시계방향으로 1칸 이동
- 5분 후: 시계방향으로 2칸 이동

이후에도 같은 패턴으로 계속 이동합니다.

점프 거리가 연못의 개수보다 크더라도 원형으로 연결되어 있으므로 계속 시계방향으로 이동합니다.

## 전염병의 확산

처음 0분에는 **1번 개구리만 전염병에 감염**되어 있고, 나머지 개구리들은 모두 건강합니다.

전염병은 다음 규칙에 따라 확산됩니다.

1. 모든 개구리는 매분 동시에 점프합니다.
2. 감염된 개구리와 건강한 개구리가 같은 시각에 같은 연못에 있으면 건강한 개구리도 즉시 감염됩니다.
3. 한 번 감염된 개구리는 영원히 감염 상태를 유지합니다.
4. 감염 여부와 관계없이 모든 개구리는 정해진 점프 패턴에 따라 계속 이동합니다.
5. 감염은 같은 시각에 같은 연못에 있을 때만 발생하며, 점프 도중 서로 지나치는 것은 감염으로 취급하지 않습니다.

여러 개구리가 같은 시각에 같은 연못에 모였다면, 그중 한 마리라도 감염되어 있을 경우 나머지 개구리들도 모두 감염됩니다.

모든 개구리의 이동을 시간 제한 없이 관찰한다고 할 때, 다음 두 값을 구하는 프로그램을 작성하세요.

- **최종 감염 개구리 수:** 언젠가 전염병에 감염되는 개구리의 총수
- **마지막 감염 시각:** 새로운 개구리가 마지막으로 감염되는 시각(분)

단, 최초 감염자인 1번 개구리의 감염 시각은 0분입니다. 다른 개구리가 한 마리도 감염되지 않는다면 마지막 감염 시각은 0입니다.

## 입력

각 테스트 케이스의 입력은 다음과 같습니다.

첫 번째 줄에는 세 정수 `N R K`가 주어집니다.

- `N`: 원형으로 배치된 연못의 수
- `R`: 개구리의 수
- `K`: 각 개구리가 반복하는 점프 패턴의 길이

두 번째 줄에는 R개의 정수 `B₁ B₂ ... Bᵣ`이 주어집니다. `Bᵢ`는 i번 개구리가 0분에 위치한 연못의 번호입니다. 모든 개구리의 시작 위치는 서로 다릅니다.

이후 R개의 줄에 걸쳐 각 개구리의 점프 패턴이 주어집니다.

i번째 줄에는 K개의 정수 `Aᵢ,₁ Aᵢ,₂ ... Aᵢ,ₖ`가 주어지며, 이는 i번 개구리가 1분마다 순서대로 이동하는 칸 수를 의미합니다.

여러 테스트 케이스가 입력될 수 있으며, 입력이 끝날 때까지 처리합니다.

## 출력

각 테스트 케이스마다 다음 두 정수를 공백으로 구분해 출력합니다.

`최종_감염_개구리_수 마지막_감염_시각`

## 예제 입력

```text
5 2 3
2 4
1 2 1
1 1 1
```

## 예제 출력

```text
2 5
```

## 예제 설명

연못은 총 5개이며, 2마리의 개구리가 있습니다.

**1번 개구리**

- 시작 연못: 2번
- 점프 패턴: `[1, 2, 1]`
- 초기 상태: 감염

**2번 개구리**

- 시작 연못: 4번
- 점프 패턴: `[1, 1, 1]`
- 초기 상태: 건강

시간에 따른 위치는 다음과 같습니다.

| 시간 | 1번 개구리 | 2번 개구리 | 감염 발생 |
|---|---|---|---|
| 0분 | 2번 | 4번 | 없음 |
| 1분 | 3번 | 5번 | 없음 |
| 2분 | 5번 | 1번 | 없음 |
| 3분 | 1번 | 2번 | 없음 |
| 4분 | 2번 | 3번 | 없음 |
| **5분** | **4번** | **4번** | **2번 개구리 감염** |

5분이 되었을 때 두 개구리가 동시에 4번 연못에 도착합니다.

1번 개구리는 이미 감염되어 있으므로 2번 개구리에게 전염병이 전파됩니다.

따라서 최종적으로 감염되는 개구리는 2마리이며, 마지막 감염 시각은 5분입니다.
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

