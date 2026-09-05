#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

int N;
int maxDepth;

vector<long long> chainValue;
vector<pair<int, int>> parentPair;

// 현재 pos까지 만들었을 때
// maxDepth 이내에 N을 만들 수 있는지 탐색
bool dfs(int pos) {
    long long current = chainValue[pos];

    // 정확히 허용된 곱셈 횟수만큼 사용
    if (pos == maxDepth) {
        return current == N;
    }

    // -----------------------------
    // 가지치기:
    // 남은 횟수 동안 계속 제곱하더라도 N에 도달하지 못하면 실패
    // -----------------------------
    long long maximumPossible = current;

    for (int i = pos; i < maxDepth; i++) {
        maximumPossible *= 2;

        if (maximumPossible >= N)
            break;
    }

    if (maximumPossible < N)
        return false;

    // 같은 값을 여러 방식으로 만드는 것을 방지
    unordered_set<long long> used;

    struct Candidate {
        long long value;
        int left;
        int right;
    };

    vector<Candidate> candidates;

    // 이전에 만든 지수 두 개를 더한다.
    for (int i = pos; i >= 0; i--) {
        for (int j = i; j >= 0; j--) {
            long long next = chainValue[i] + chainValue[j];

            // addition chain은 증가하는 형태만 고려
            if (next <= current)
                continue;

            if (next > N)
                continue;

            if (used.count(next))
                continue;

            used.insert(next);

            candidates.push_back({
                next,
                i,
                j
            });
        }
    }

    // 큰 값을 먼저 시도하면 보통 더 빨리 N에 도달
    sort(candidates.begin(), candidates.end(),
         [](const Candidate& a, const Candidate& b) {
             return a.value > b.value;
         });

    for (const Candidate& c : candidates) {
        chainValue[pos + 1] = c.value;
        parentPair[pos + 1] = {c.left, c.right};

        if (dfs(pos + 1))
            return true;
    }

    return false;
}

int main() {
    cin >> N;

    if (N <= 0)
        return 0;

    if (N == 1) {
        cout << "Minimum multiplications: 0\n";
        cout << "x1 := a\n";
        cout << "b := x1\n";
        return 0;
    }

    // 최소 가능한 depth:
    // 한 번 곱할 때 최대 2배 증가하므로 ceil(log2(N))
    int lowerBound = 0;
    long long x = 1;

    while (x < N) {
        x *= 2;
        lowerBound++;
    }

    // 최악의 경우
    // 1 -> 2 -> 3 -> ... -> N
    for (maxDepth = lowerBound; maxDepth <= N - 1; maxDepth++) {

        chainValue.assign(maxDepth + 1, 0);
        parentPair.assign(maxDepth + 1, {-1, -1});

        chainValue[0] = 1;

        if (dfs(0)) {
            cout << "Minimum multiplications: "
                 << maxDepth << "\n\n";

            cout << "Optimal addition chain:\n";

            for (int i = 0; i <= maxDepth; i++) {
                cout << chainValue[i];

                if (i != maxDepth)
                    cout << " -> ";
            }

            cout << "\n\n";

            cout << "Generated code:\n";

            cout << "x1 := a;    // a^1\n";

            for (int i = 1; i <= maxDepth; i++) {
                int left = parentPair[i].first;
                int right = parentPair[i].second;

                cout << "x" << i + 1
                     << " := x" << left + 1
                     << " * x" << right + 1
                     << ";    // a^" << chainValue[i]
                     << '\n';
            }

            cout << "b := x" << maxDepth + 1 << ";\n";

            break;
        }
    }

    return 0;
}