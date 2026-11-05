#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> board;

// Check column and both upper diagonals (rows below are still empty)
bool isSafe(int row, int col) {
    for (int i = 0; i < row; i++)
        if (board[i][col]) return false;

    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j]) return false;

    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        if (board[i][j]) return false;

    return true;
}

bool solve(int row) {
    if (row == n)                    // all queens placed
        return true;

    for (int col = 0; col < n; col++) {
        if (isSafe(row, col)) {
            board[row][col] = 1;     // place queen
            if (solve(row + 1))
                return true;
            board[row][col] = 0;     // backtrack
        }
    }
    return false;
}

int main() {
    int firstCol;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter column of first queen (row 0), 0-indexed: ";
    cin >> firstCol;

    board.assign(n, vector<int>(n, 0));
    board[0][firstCol] = 1;          // first queen already placed

    if (solve(1)) {                  // start from row 1
        for (auto &row : board) {
            for (int cell : row)
                cout << (cell ? "Q " : ". ");
            cout << "\n";
        }
    } else {
        cout << "No solution\n";
    }
}
