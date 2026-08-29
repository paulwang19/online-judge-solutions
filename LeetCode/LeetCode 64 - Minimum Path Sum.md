# LeetCode 64 - Minimum Path Sum

## 程式碼

```cpp
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(200, vector<int>(200, 0));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                dp[i][j] = grid[i][j];
                if (i > 0 && j > 0) {
                    dp[i][j] += min(dp[i - 1][j], dp[i][j - 1]);
                }
                else if (i > 0) {
                    dp[i][j] += dp[i - 1][j];
                }
                else if (j > 0) {
                    dp[i][j] += dp[i][j - 1];
                }
            }
        }

        return dp[grid.size() - 1][grid[0].size() - 1];
    }
};
```
