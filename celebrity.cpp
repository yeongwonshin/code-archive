#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<int>> relation;
int questionCount = 0;

// a가 b를 알고 있으면 true
bool knows(int a, int b) {
    questionCount++;
    return relation[a][b];
}

int findCelebrity() {
    if (N == 0)
        return -1;

    // 1. 후보 선택
    int candidate = 0;

    for (int i = 1; i < N; i++) {
        if (knows(candidate, i)) {
            // candidate는 누군가를 알고 있으므로 celebrity가 아님
            candidate = i;
        }
        // candidate가 i를 모르면
        // i는 모든 사람에게 알려진 사람이 아니므로 탈락
    }

    // 2. 후보 검증
    for (int i = 0; i < N; i++) {
        if (i == candidate)
            continue;

        // celebrity는 아무도 몰라야 한다.
        if (knows(candidate, i))
            return -1;

        // 모든 사람은 celebrity를 알아야 한다.
        if (!knows(i, candidate))
            return -1;
    }

    return candidate;
}

int main() {
    cin >> N;

    relation.assign(N, vector<int>(N));

    // relation[i][j] = 1 이면 i가 j를 안다.
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> relation[i][j];
        }
    }

    int result = findCelebrity();

    if (result == -1)
        cout << "No celebrity\n";
    else
        cout << "Celebrity: " << result << '\n';

    cout << "Questions: " << questionCount << '\n';

    return 0;
}