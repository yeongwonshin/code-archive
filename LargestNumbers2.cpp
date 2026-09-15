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