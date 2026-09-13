#include <iostream>
#include <vector>
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

    int row = 0;
    int col = 0;

    while (row < N && col < N) {
        if (matrix[row][col] == k) {
            // 문제 예시처럼 1-based index 출력
            cout << "(" << row + 1 << ", " << col + 1 << ")\n";
            return 0;
        }

        if (matrix[row][col] < k) {
            // 현재 column의 아래쪽은 모두 더 작거나 같으므로 제외
            col++;
        }
        else {
            // 현재 row의 오른쪽은 모두 더 크거나 같으므로 제외
            row++;
        }
    }

    cout << "Not Found\n";

    return 0;
}