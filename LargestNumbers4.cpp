//입력이 2개가 아니라 여러 개일 땐?
#include <iostream>
#include <vector>
using namespace std;

pair<int, int> findPosition(const vector<vector<int>>& matrix, int k) {
    int N = matrix.size();

    int row = 0;
    int col = 0;

    while (row < N && col < N) {
        if (matrix[row][col] == k) {
            return {row, col};
        }

        if (matrix[row][col] < k) {
            col++;
        }
        else {
            row++;
        }
    }

    return {-1, -1};
}

int main() {
    int N;
    cin >> N;

    vector<vector<int>> matrix(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }

    int M;  // 찾을 값의 개수
    cin >> M;

    vector<int> targets(M);

    for (int i = 0; i < M; i++) {
        cin >> targets[i];
    }

    for (int k : targets) {
        pair<int, int> pos = findPosition(matrix, k);

        if (pos.first != -1) {
            cout << k << ": ("
                 << pos.first + 1 << ", "
                 << pos.second + 1 << ")\n";
        }
        else {
            cout << k << ": Not Found\n";
        }
    }

    return 0;
}