//서로 다른 여러 값(예: 4와 5)의 위치를 찾는 프로그램

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

    return {-1, -1};   // 못 찾음
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

    vector<int> targets = {4, 5};

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