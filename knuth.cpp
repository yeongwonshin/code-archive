/*1. 문제 설명
소설의 여러 장이 각각 다른 파일에 저장되어 있다.
파일은 처음부터 끝까지 순서대로 나열되어 있고, 서로 인접한 두 파일 또는 파일 묶음만 합칠 수 있다.
두 파일의 크기가 각각 \(A,B\)이면 합치는 비용은
\[
A+B
\]

이다.
합쳐진 파일은 다시 다른 파일과 합칠 수 있다. 모든 파일을 하나로 합칠 때 필요한 최소 총비용을 구하시오.
예를 들어 파일이 다음과 같이 주어진다.
\[
[40,30,30,50]
\]

어떤 순서로 합치느냐에 따라 누적 비용이 달라진다.
2. 입력과 출력
입력
- 첫 번째 줄: 테스트 케이스 개수 \(T\)
- 각 테스트 케이스의 첫 번째 줄: 파일 개수 \(K\) (\(3\le K\le500\))
- 다음 줄: 파일 크기 \(K\)개 (각 크기는 1 이상 10,000 이하)
출력
각 테스트 케이스마다 파일을 모두 합치는 최소 비용을 출력한다.
예제 입력
1
4
40 30 30 50


예제 출력
300
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = (1LL << 60);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int K;
        cin >> K;

        vector<ll> prefix(K + 1, 0);

        for (int i = 1; i <= K; i++) {
            ll x;
            cin >> x;
            prefix[i] = prefix[i - 1] + x;
        }

        vector<vector<ll>> dp(
            K + 2, vector<ll>(K + 2, 0)
        );

        vector<vector<int>> opt(
            K + 2, vector<int>(K + 2, 0)
        );

        // 길이가 1인 구간
        for (int i = 1; i <= K; i++) {
            dp[i][i] = 0;
            opt[i][i] = i;
        }

        // 구간 길이를 증가시키면서 계산
        for (int len = 2; len <= K; len++) {
            for (int i = 1; i + len - 1 <= K; i++) {
                int j = i + len - 1;

                ll sum = prefix[j] - prefix[i - 1];

                dp[i][j] = INF;

                // Knuth 최적화:
                // 검사해야 할 분할 위치를 제한
                int left = max(i, opt[i][j - 1]);
                int right = min(j - 1, opt[i + 1][j]);

                for (int k = left; k <= right; k++) {
                    ll cost = dp[i][k]
                            + dp[k + 1][j]
                            + sum;

                    if (cost < dp[i][j]) {
                        dp[i][j] = cost;
                        opt[i][j] = k;
                    }
                }
            }
        }

        cout << dp[1][K] << '\n';
    }

    return 0;
}
