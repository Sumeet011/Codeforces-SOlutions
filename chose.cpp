#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to count factors of `factor` in `num`
int countFactors(int num, int factor) {
    int count = 0;
    while (num > 0 && num % factor == 0) {
        count++;
        num /= factor;
    }
    return count;
}

// Function to find the path with the minimum trailing zeros
void minTrailingZerosPath(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, {INT_MAX, INT_MAX}));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(n, {-1, -1}));

    // Initialize starting point
    dp[0][0].first = countFactors(matrix[0][0], 2);
    dp[0][0].second = countFactors(matrix[0][0], 5);

    // Fill the DP table
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == 0 && j == 0) continue;

            int count_2 = countFactors(matrix[i][j], 2);
            int count_5 = countFactors(matrix[i][j], 5);
            
            // From the cell above
            if (i > 0) {
                int prev_2 = dp[i - 1][j].first;
                int prev_5 = dp[i - 1][j].second;
                if (prev_2 + count_2 < dp[i][j].first ||
                    (prev_2 + count_2 == dp[i][j].first && prev_5 + count_5 < dp[i][j].second)) {
                    dp[i][j] = {prev_2 + count_2, prev_5 + count_5};
                    parent[i][j] = {i - 1, j};
                }
            }

            // From the cell on the left
            if (j > 0) {
                int prev_2 = dp[i][j - 1].first;
                int prev_5 = dp[i][j - 1].second;
                if (prev_2 + count_2 < dp[i][j].first ||
                    (prev_2 + count_2 == dp[i][j].first && prev_5 + count_5 < dp[i][j].second)) {
                    dp[i][j] = {prev_2 + count_2, prev_5 + count_5};
                    parent[i][j] = {i, j - 1};
                }
            }
        }
    }

    // Get the minimum trailing zeros
    int trailing_zeros = min(dp[n - 1][n - 1].first, dp[n - 1][n - 1].second);
    cout << trailing_zeros << endl;

    // Reconstruct the path
    string path;
    int x = n - 1, y = n - 1;
    while (x != 0 || y != 0) {
        auto [prev_x, prev_y] = parent[x][y];
        if (prev_x == x - 1) {
            path.push_back('D'); // Move down
        } else {
            path.push_back('R'); // Move right
        }
        x = prev_x;
        y = prev_y;
    }

    // Reverse the path to get it from start to end
    reverse(path.begin(), path.end());
    cout << path << endl;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    minTrailingZerosPath(matrix);
    return 0;
}
