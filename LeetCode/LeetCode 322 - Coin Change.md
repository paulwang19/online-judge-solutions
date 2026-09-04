# LeetCode 322 - Coin Change

## 程式碼

```cpp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) {
            return 0;
        }

        vector<int> dp(10001, -1);
        dp[0] = 0;
        for (int i = 0; i < coins.size(); i++) {
            for (int j = 1; j <= amount; j++) {
                if (j - coins[i] >= 0 && dp[j - coins[i]] != -1) {
                    if (dp[j] == -1) dp[j] = dp[j - coins[i]] + 1;
                    else             dp[j] = min(dp[j], dp[j - coins[i]] + 1);
                }
            }
        }

        return dp[amount];
    }
};
```
