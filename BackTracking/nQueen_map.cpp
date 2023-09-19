
// Using map

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

unordered_map<int, bool> rowCheck;
unordered_map<int, bool> upperLeftDiagonalCheck;
unordered_map<int, bool> bottomLeftDiagonlChek;

void printSolution(vector<vector<char>> &board, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl
         << endl;
}

bool isSafe(int row, int col, vector<vector<char>> &board, int n) // O(1)
{
    if (rowCheck[row] == true)
    {
        return false;
    }
    if (upperLeftDiagonalCheck[n - 1 + col - row] == true)
    {
        return false;
    }
    if (bottomLeftDiagonlChek[row + col] == true)
    {
        return false;
    }

    return true;
}

void solve(vector<vector<char>> &board, int col, int n)
{
    // base case
    if (col >= n) // last col tak
    {
        printSolution(board, n);
        return;
    }

    // 1 casesolve karna h, baaki recursion sambhal lega
    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, board, n))
        {
            // rakh do
            board[row][col] = 'Q';

            rowCheck[row] = true;
            upperLeftDiagonalCheck[n - 1 + col - row] = true;
            bottomLeftDiagonlChek[row + col] = true;

            // recursion solution laega
            solve(board, col + 1, n);
            // backtracking
            board[row][col] = '-';
            rowCheck[row] = false;
            upperLeftDiagonalCheck[n - 1 + col - row] = false;
            bottomLeftDiagonlChek[row + col] = false;
        }
    }
}

int main()
{
    int n = 4;
    vector<vector<char>> board(n, vector<char>(n, '-'));
    int col = 0;
    // 0-> empty cell
    //  1->Queen at the cell
    solve(board, col, n);

    return 0;
}