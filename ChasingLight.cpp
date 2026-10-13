
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Light {
    ll x, y, s, e;
};

ll dist(const Light& a, const Light& b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<Light> lights(N);

    for (int i = 0; i < N; i++) {
        cin >> lights[i].x >> lights[i].y
            >> lights[i].s >> lights[i].e;
    }

    // 빛이 끝나는 시간 기준 오름차순 정렬
    sort(lights.begin(), lights.end(),
         [](const Light& a, const Light& b) {
             return a.e < b.e;
         });

    const ll NEG = -(1LL << 60);
    vector<ll> dp(N, NEG);

    ll ans = 0;

    for (int i = 0; i < N; i++) {
        // 시작점 (0, 0)에서 직접 이동
        ll arrival = abs(lights[i].x) + abs(lights[i].y);

        if (arrival <= lights[i].e) {
            ll start = max(arrival, lights[i].s);
            dp[i] = lights[i].e - start;
        }

        // 이전 빛 j에서 현재 빛 i로 이동
        for (int j = 0; j < i; j++) {
            if (dp[j] == NEG) continue;

            ll moveTime = dist(lights[j], lights[i]);
            ll nextArrival = lights[j].e + moveTime;

            if (nextArrival > lights[i].e) continue;

            ll start = max(nextArrival, lights[i].s);
            ll gain = lights[i].e - start;

            dp[i] = max(dp[i], dp[j] + gain);
        }

        ans = max(ans, dp[i]);
    }

    cout << ans << '\n';

    return 0;
}
