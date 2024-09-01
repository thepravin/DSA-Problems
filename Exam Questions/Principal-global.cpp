#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to perform DFS and calculate the maximum cells visited
int dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int x, int y, int m, int n) {
    // If the position is out of bounds or a wall or already visited, return 0
    if (x < 0 || y < 0 || x >= m || y >= n || board[x][y] == 'X' || visited[x][y])
        return 0;

    // Mark the cell as visited
    visited[x][y] = true;

    // Count the current cell
    int count = 1;

    // Explore all four possible directions
    count += dfs(board, visited, x + 1, y, m, n); // Move Down
    count += dfs(board, visited, x - 1, y, m, n); // Move Up
    count += dfs(board, visited, x, y + 1, m, n); // Move Right
    count += dfs(board, visited, x, y - 1, m, n); // Move Left

    return count;
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<char>> board(m, vector<char>(n));
    vector<vector<bool>> visited(m, vector<bool>(n, false));

    // Read the board
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    // Start DFS from the top-left corner (0, 0)
    int maxCellsVisited = dfs(board, visited, 0, 0, m, n);

    // Print the result
    cout << maxCellsVisited << endl;

    return 0;
}

// Char increase 1

// #include <iostream>
// #include <unordered_set>
// using namespace std;

// void helper(string &str)
// {

//     for (int i = 0; i < str.length(); i++)
//     {
//         if (!isalpha(str[i]))
//         {

//             continue;
//         }

//         str[i] += 1;
//     }
// }

// int main()
// {
//     string str = "Today is Wednesday 12-04-23";

//     helper(str);
//     cout << str << endl;

//     return 0;
// }
