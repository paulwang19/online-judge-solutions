# LeetCode 62 - Unique Paths

## 程式碼

```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; i++) {
            dp[i][0] = 1;
        }

        for (int c = 1; c < n; c++) {
            dp[0][c] = 1;
            for (int r = 1; r < m; r++) {
                dp[r][c] = dp[r][c - 1] + dp[r - 1][c];
            }
        }

        return dp[m - 1][n - 1];
    }
};
```
