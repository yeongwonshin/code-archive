//배열에 k가 여러 군데 존재할 때, 이 중복되는 위치를 모두 출력하는 프로그램
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, k;
    cin >> N >> k;

    vector<vector<int>> matrix(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }

    bool found = false;

    for (int row = 0; row < N; row++) {

        auto first = lower_bound(
            matrix[row].begin(),
            matrix[row].end(),
            k
        );
//k이상의 첫 번째 원소를 찾는다. lower_bound는 이진 탐색을 사용하므로 O(logN) 시간에 찾을 수 있다.
        auto last = upper_bound(
            matrix[row].begin(),
            matrix[row].end(),
            k
        );

        for (auto it = first; it != last; ++it) {
            int col = it - matrix[row].begin();

            cout << "("
                 << row + 1 << ", "
                 << col + 1 << ")\n";

            found = true;
        }
    }

    if (!found)
        cout << "Not Found\n";

    return 0;
}
//위 프로그램은 O(NlogN) 시간에 k의 위치를 모두 찾는다.
/* 아래의 프로그램은 O(N) 시간에 k의 위치를 모두 찾는다.

vector<pair<int, int>> findAllK(int n, int k) {
    vector<pair<int, int>> positions;

    int left = 1;
    int right = 1;

    for (int row = 1; row <= n; row++) {

        // K 이상인 첫 번째 열 탐색
        while (left <= n && query_cell(row, left) < k)
            left++;

        // K 초과인 첫 번째 열 탐색
        while (right <= n && query_cell(row, right) <= k)
            right++;

        // [left, right) 구간은 모두 K
        for (int col = left; col < right; col++)
            positions.push_back({row, col});
    }

    return positions;
}


*/