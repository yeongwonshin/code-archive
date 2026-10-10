#include <iostream>
#include <cassert>
#include <cstdlib>

/**
 * @brief Queries the value stored at cell (r, c).
 * @param r The row index, where 1 <= r <= n.
 * @param c The column index, where 1 <= c <= n.
 * @return The integer stored at cell (r, c).
 */
int query_cell(int r, int c) {
    int result;
    std::cout << "? " << r << ' ' << c << std::endl;

    if (!(std::cin >> result)) {
        std::exit(0);
    }

    return result;
}

/**
 * @brief Submits cell (r, c) as the position of K and terminates the program.
 * @param r The row index, where 1 <= r <= n.
 * @param c The column index, where 1 <= c <= n.
 */
void answer_with_cell(int r, int c) {
    int result;
    std::cout << "! " << r << ' ' << c << std::endl;

    if (!(std::cin >> result)) {
        std::exit(0);
    }

    assert(result == 0 || result == 1);
    std::exit(0);
}

/**
 * @brief Submits that K does not occur in the matrix and terminates the program.
 */
void answer_without_cell() {
    int result;
    std::cout << "! -1 -1" << std::endl;

    if (!(std::cin >> result)) {
        std::exit(0);
    }

    assert(result == 0 || result == 1);
    std::exit(0);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    // TODO: write your logic here!
    // Each row is sorted in non-decreasing order from left to right.
    // Each column is sorted in non-increasing order from top to bottom.
    // You can use the functions `query_cell`, `answer_with_cell`,
    // and `answer_without_cell`.
    // You may call `query_cell` at most 2 * n - 1 times.
    // Call exactly one of the two answer functions, exactly once.
    // Do not modify the provided functions or perform additional
    // standard input/output operations outside these functions.
    int row = 1;
    int col = 1;
    
    while(row<=n&&col<=n){
         int value = query_cell(row, col);
         if(value==k) answer_with_cell(row, col);
         if(value<k) col++;
         else row++;
         
    }
    answer_without_cell();

    return 0;
}