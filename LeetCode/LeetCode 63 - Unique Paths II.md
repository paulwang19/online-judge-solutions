# LeetCode 63 - Unique Paths II

## 程式碼

```cpp
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            if (obstacleGrid[i][0] == 1) {
                break;
            }

            dp[i][0] = 1;
        }

        for (int c = 1; c < n; c++) {
            if (obstacleGrid[0][c] == 0 && dp[0][c - 1] != 0) {
                dp[0][c] = 1;
            }

            for (int r = 1; r < m; r++) {
                if (obstacleGrid[r][c] == 0) {
                    dp[r][c] = dp[r - 1][c] + dp[r][c - 1];
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};
```
