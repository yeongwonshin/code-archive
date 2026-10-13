
#include <bits/stdc++.h>
using namespace std;

const long long MAX_W = 1000000000LL;

vector<long long> wealth;
long long queryCount = 0;

// i번 사람이 x원 이상 가지고 있는지 질문
bool ask(int i, long long x) {
    queryCount++;
    return wealth[i] >= x;
}

// 이분 탐색으로 i번 사람의 정확한 재산 확인
long long binarySearch(int i, long long low, long long high) {
    while (low < high) {
        long long mid = low + (high - low + 1) / 2;

        if (ask(i, mid)) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }

    return low;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    // 로컬 테스트용 숨겨진 재산 정보
    wealth.resize(N + 1);

    for (int i = 1; i <= N; i++) {
        cin >> wealth[i];
    }

    // 첫 번째 사람의 정확한 재산 확인
    int candidate = 1;
    long long W = binarySearch(1, 0, MAX_W);

    // 나머지 사람 확인
    for (int i = 2; i <= N; i++) {
        if (W == MAX_W) break;

        // 현재 최대 재산보다 많은지 질문
        if (!ask(i, W + 1)) {
            continue;
        }

        // 더 부유하다면 정확한 재산 확인
        long long current = binarySearch(i, W + 1, MAX_W);

        candidate = i;
        W = current;
    }

    cout << candidate << " " << W << '\n';

    return 0;
}
