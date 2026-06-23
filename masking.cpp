/*문제 요약

정수 배열 A[0], A[1], ..., A[N-1]가 주어진다.
각 숫자 앞에 + 또는 -를 하나씩 붙여서 전체 합이 목표값 K가 되도록 만드는 문제이다.

즉, 다음과 같은 식을 만들어야 한다.

±A[0] ± A[1] ± A[2] ... ± A[N-1] = K

가능한 식이 있으면 그 식을 출력하고, 불가능하면

There is no solution.

을 출력한다.

N이 최대 35 정도로 크기 때문에 모든 경우의 수 2^N을 직접 확인하면 너무 오래 걸린다.

예제 입력 / 출력 1개
입력
1
3
1 2 3
0
출력
-(1)-(2)+(3)=0

설명:

-1 -2 +3 = 0

이므로 목표값 0을 만들 수 있다.
*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

struct Node {
    ll sum;
    unsigned int mask;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N;
        ll K;
        ll A[35];

        cin >> N;

        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }

        cin >> K;

        int n1 = N / 2;
        int n2 = N - n1;

        unsigned int size2 = 1u << n2;

        vector<Node> right;
        right.reserve(size2);

        for (unsigned int mask = 0; mask < size2; mask++) {
            ll sum = 0;

            for (int i = 0; i < n2; i++) {
                if (mask & (1u << i)) {
                    sum += A[n1 + i];
                } else {
                    sum -= A[n1 + i];
                }
            }

            right.push_back({sum, mask});
        }

        sort(right.begin(), right.end(), [](const Node& a, const Node& b) {
            return a.sum < b.sum;
        });

        unsigned int size1 = 1u << n1;

        bool found = false;
        unsigned int answerLeft = 0;
        unsigned int answerRight = 0;

        for (unsigned int mask = 0; mask < size1; mask++) {
            ll sum = 0;

            for (int i = 0; i < n1; i++) {
                if (mask & (1u << i)) {
                    sum += A[i];
                } else {
                    sum -= A[i];
                }
            }

            ll need = K - sum;

            auto it = lower_bound(
                right.begin(),
                right.end(),
                need,
                [](const Node& node, ll value) {
                    return node.sum < value;
                }
            );

            if (it != right.end() && it->sum == need) {
                found = true;
                answerLeft = mask;
                answerRight = it->mask;
                break;
            }
        }

        if (!found) {
            cout << "There is no solution.\n";
        } else {
            for (int i = 0; i < n1; i++) {
                if (answerLeft & (1u << i)) {
                    cout << "+(" << A[i] << ")";
                } else {
                    cout << "-(" << A[i] << ")";
                }
            }

            for (int i = 0; i < n2; i++) {
                if (answerRight & (1u << i)) {
                    cout << "+(" << A[n1 + i] << ")";
                } else {
                    cout << "-(" << A[n1 + i] << ")";
                }
            }

            cout << "=" << K << '\n';
        }
    }

    return 0;
}