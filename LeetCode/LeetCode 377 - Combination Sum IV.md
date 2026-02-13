# LeetCode 377 - Combination Sum IV

## 程式碼

```cpp
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1;
        for (int curTarget = 1; curTarget <= target; curTarget++) {
            for (int n : nums) {
                if (curTarget - n >= 0) {
                    dp[curTarget] += dp[curTarget - n];
                }
            }
        }

        return dp[target];
    }
};
```
