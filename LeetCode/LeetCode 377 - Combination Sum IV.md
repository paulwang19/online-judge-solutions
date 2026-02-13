# LeetCode 377 - Combination Sum IV

## 想法

假設要組合的目標是 4，我們有 1、2、3 可以用，那我們可以將它拆成 3 加上一個 1，如此，只要知道組合成 3 的方法數，就可以用組合 3 的方法加上一個 1 來組合出 4。同理，目標 4 亦可以拆成 2 加上 2、或是 1 加上 3，如此，只要知道組合成 2 的方法數和組合成 3 的方法數，就分別可以得到從 2 加一個 2 組合成 4 的方法數，以及從 1 加一個 3 組合成 4 的方法數。

因此，組合成 4 的方法數，就等於組合成 3 的方法數加上組合成 2 的方法數加上組合成 1 的方法數。

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
