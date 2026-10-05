#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    const double PI = acos(-1.0);
    const double EPS = 1e-12;

    vector<double> angle(N);

    for (int i = 0; i < N; i++) {
        double x, y;
        cin >> x >> y;

        double theta = atan2(y, x);

        // [-pi, pi] -> [0, 2pi)
        if (theta < 0)
            theta += 2.0 * PI;

        angle[i] = theta;
    }

    sort(angle.begin(), angle.end());

    double maxGap = 0.0;

    // 인접한 점 사이 gap
    for (int i = 0; i < N - 1; i++) {
        maxGap = max(maxGap, angle[i + 1] - angle[i]);
    }

    // 마지막 점 -> 첫 번째 점으로 돌아가는 gap
    double circularGap =
        angle[0] + 2.0 * PI - angle[N - 1];

    maxGap = max(maxGap, circularGap);

    // closed half-circle이므로 정확히 pi도 허용
    if (maxGap + EPS >= PI)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}