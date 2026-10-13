
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    const long long MAX_W = 1000000000LL;

    // i번 사람의 재산이 x 이상인지 질문
    auto ask = [&](int i, long long x) -> bool {
        cout << "? " << i << ' ' << x << endl;

        string response;
        if (!(cin >> response) || response == "-1")
            exit(0);

        if (response != "Yes" && response != "No")
            exit(0);

        return response == "Yes";
    };

    // i번 사람의 정확한 재산을 이분 탐색
    // 재산이 lo 이상이라는 사실을 알고 있다고 가정
    auto findWealth = [&](int i, long long lo) -> long long {
        long long hi = MAX_W;

        while (lo < hi) {
            long long mid = lo + (hi - lo + 1) / 2;

            if (ask(i, mid))
                lo = mid;
            else
                hi = mid - 1;
        }

        return lo;
    };

    // 사람들의 검사 순서를 무작위로 변경
    vector<int> order(N);
    iota(order.begin(), order.end(), 1);

    mt19937 rng(
        (unsigned)chrono::steady_clock::now()
            .time_since_epoch().count()
    );
    shuffle(order.begin(), order.end(), rng);

    // 첫 번째 후보의 정확한 재산 확인
    int candidate = order[0];
    long long W = findWealth(candidate, 0);

    // 나머지 사람 확인
    for (int k = 1; k < N; k++) {
        if (W == MAX_W)
            break;

        int i = order[k];

        // 현재 최대 재산보다 많은 경우에만 갱신
        if (ask(i, W + 1)) {
            W = findWealth(i, W + 1);
            candidate = i;
        }
    }

    // 최종 정답 출력
    cout << "! " << candidate << ' ' << W << endl;

    return 0;
}
