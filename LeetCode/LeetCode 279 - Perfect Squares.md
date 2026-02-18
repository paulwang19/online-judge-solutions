# LeetCode 279 - Perfect Squares

## 程式碼

```cpp
class Solution {
public:
    int numSquares(int n) {
        vector<int> squares;
        for (int i = 1; i * i <= 10000; i++) {
            squares.push_back(i * i);
        }

        vector<int> dp(10005, 0);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int c = 0; c < squares.size() && squares[c] <= i; c++) {
                if (dp[i] == 0 || dp[i - squares[c]] < dp[i]) {
                    dp[i] = dp[i - squares[c]] + 1;
                }
            }
        }
        
        return dp[n];
    }
};
```
