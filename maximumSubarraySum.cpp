#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    long long cur = 0;
    long long ans = 0;

    for (int i = 0; i < n; ++i) {
        long long x;
        cin >> x;

        cur = max(0LL, cur + x);
        ans = max(ans, cur);
    }

    cout << ans << '\n';

    return 0;
}