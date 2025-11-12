# LeetCode 198 - House Robber

## 想法

就是從第一間房屋開始，每次計算走到當前這裡時，你可以搶多少錢。

假設我走到某間房屋，而我要計算當下搶最多錢的作法，就是判斷要不要搶現在這間房屋。如果已經搶了前一間房屋，那就不能搶現在這間，當前能搶的最多錢等同於在前一間房屋時能搶的最多錢；如果我前一間沒搶，那這間搶下來累計的錢一定比較多，而在前一間能搶的最多錢等同於在前兩間時能搶到的最多錢。因此我只需要知道在前一、二間房屋時能搶的最多錢分別為多少，就能比較我應不應該搶下這間房屋，進而計算我走到當前這間房屋時能搶的最多錢是多少。

## 作法

以 $nums[i]$ 表示第 $i$ 間房屋的錢，$dp[i]$ 表示走到第 $i$ 間房屋時，當前能搶下的最多錢，公式如下:

$$
dp[i] = \begin{cases}
    0 & \text{if } i = 0 \\
    \text{nums}[1] & \text{if } i = 1 \\
    \max\{ dp[i - 1], dp[i - 2] + \text{nums}[i] \} & \text{if } i \ge 2
\end{cases}
$$

## 複雜度分析

設給定的數列長度為 $n$

- 時間複雜度 : $O(n)$
- 空間複雜度 : $O(n)$

## 程式碼

```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(105, 0);
        dp[0] = 0;
        dp[1] = nums[0];
        for (int i = 2; i <= nums.size(); i++) {
            int curMoney = nums[i - 1];
            dp[i] = max(dp[i - 1], dp[i - 2] + curMoney);
        }

        return dp[nums.size()];
    }
};
```
