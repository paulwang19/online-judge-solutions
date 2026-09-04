# LeetCode 518 - Coin Change II

## 程式碼

```cpp
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<unsigned int> dp(5001, 0);
        dp[0] = 1;
        for (int i = 0; i < coins.size(); i++) {
            for (int j = 1; j <= amount; j++) {
                if (j - coins[i] >= 0) {
                    dp[j] += dp[j - coins[i]];
                }
            }
        }

        return dp[amount];
    }
};
```
