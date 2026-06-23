#include <iostream>
#include <array>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

array<array<int, 9>, 9> board;

array<int, 9> rowMask{};
array<int, 9> colMask{};//{}은 초기화
array<int, 9> boxMask{};

vector<pair<int, int>> blanks;

const int FULL = (1 << 10) - 2;
// 1~9번 비트만 사용
// 1111111110(2)

int getBoxIndex(int r, int c) {
    return (r / 3) * 3 + (c / 3);
}

void printBoard() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j];

            if (j < 8) cout << ' ';
        }
        cout << '\n';
    }
}

bool solve(int depth) {
    if (depth == (int)blanks.size()) {
        return true;
    }

    int bestIndex = depth;
    int bestMask = 0;
    int minCandidateCount = 10;

    /*
        아직 채우지 않은 빈칸들 중에서
        후보 숫자가 가장 적은 칸을 먼저 고른다.

        이게 최적화 포인트다.
    */
    for (int i = depth; i < (int)blanks.size(); i++) {
        int r = blanks[i].first;
        int c = blanks[i].second;
        int b = getBoxIndex(r, c);

        int used = rowMask[r] | colMask[c] | boxMask[b];
        int candidateMask = FULL & ~used;

        int candidateCount = __builtin_popcount((unsigned)candidateMask);

        if (candidateCount < minCandidateCount) {
            minCandidateCount = candidateCount;
            bestIndex = i;
            bestMask = candidateMask;
        }
    }

    if (minCandidateCount == 0) {
        return false;
    }

    swap(blanks[depth], blanks[bestIndex]);

    int r = blanks[depth].first;
    int c = blanks[depth].second;
    int b = getBoxIndex(r, c);

    int used = rowMask[r] | colMask[c] | boxMask[b];
    int candidateMask = FULL & ~used;

    for (int num = 1; num <= 9; num++) {
        int bit = 1 << num;

        if (candidateMask & bit) {
            board[r][c] = num;

            rowMask[r] |= bit;
            colMask[c] |= bit;
            boxMask[b] |= bit;

            if (solve(depth + 1)) {
                return true;
            }

            board[r][c] = 0;

            rowMask[r] &= ~bit;
            colMask[c] &= ~bit;
            boxMask[b] &= ~bit;
        }
    }

    swap(blanks[depth], blanks[bestIndex]);

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];

            if (board[i][j] == 0) {
                blanks.push_back({i, j});
            } else {
                int num = board[i][j];
                int bit = 1 << num;
                int b = getBoxIndex(i, j);

                rowMask[i] |= bit;
                colMask[j] |= bit;
                boxMask[b] |= bit;
            }
        }
    }

    solve(0);
    printBoard();

    return 0;
}