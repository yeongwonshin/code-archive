#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

using namespace std;

bool ask_a_to_know_b(int a, int b) {
    int result;
    cout << "? " << a << ' ' << b << endl;
    cin >> result;

    assert(result == 0 || result == 1);
    return result;
}

bool answer(int x) {
    int result;
    cout << "! " << x << endl;
    cin >> result;

    assert(result == 0 || result == 1);
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    if (n <= 0) {
        answer(-1);
        return 0;
    }

    vector<int> eliminatedBy(n + 1, 0);
    vector<unsigned char> knownType(n + 1, 0);

    vector<int> current(n);
    vector<int> next(n);

    auto play_match = [&](int a, int b) -> int {
        bool knows = ask_a_to_know_b(a, b);

        if (knows) {
            eliminatedBy[a] = b;
            knownType[a] = 1;
            return b;
        }
        else {
            eliminatedBy[b] = a;
            knownType[b] = 2;
            return a;
        }
    };

    int p = 1;

    while (p <= n / 2)
        p *= 2;

    int preliminaryMatches = n - p;
    int currentCount = 0;

    // 예선
    for (int i = 0; i < preliminaryMatches; i++) {
        int a = 2 * i + 1;
        int b = 2 * i + 2;

        current[currentCount++] = play_match(a, b);
    }

    // 예선을 치르지 않은 사람들 추가
    for (int person = 2 * preliminaryMatches + 1;
         person <= n;
         person++) {

        current[currentCount++] = person;
    }

    // 본선 토너먼트
    while (currentCount > 1) {
        int nextCount = 0;

        for (int i = 0; i < currentCount; i += 2) {
            int a = current[i];
            int b = current[i + 1];

            next[nextCount++] = play_match(a, b);
        }

        swap(current, next);

        currentCount = nextCount;
    }

    int candidate = current[0];

    // 최종 후보 검증
    for (int i = 1; i <= n; i++) {

        if (i == candidate)
            continue;

        bool candidateDoesNotKnowI =
            (eliminatedBy[i] == candidate &&
             knownType[i] == 2);

        if (!candidateDoesNotKnowI) {

            if (ask_a_to_know_b(candidate, i)) {
                answer(-1);
                return 0;
            }
        }

        bool iKnowsCandidate =
            (eliminatedBy[i] == candidate &&
             knownType[i] == 1);

        if (!iKnowsCandidate) {

            if (!ask_a_to_know_b(i, candidate)) {
                answer(-1);
                return 0;
            }
        }
    }

    answer(candidate);

    return 0;
}