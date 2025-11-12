# LeetCode 213 - House Robber II

## 想法

想法大致與 [House Robber](./LeetCode%20198%20-%20House%20Robber.md) 相同，差在需要額外考慮不能同時搶第一棟和最後一棟，因此，分成**能搶第一棟**和**不能搶第一棟**兩種情況討論，算出較大的結果即為答案。

- 能搶第一棟: 最後一棟不能搶，計算直到倒數第二棟時能搶的最多錢
- 不能搶第一棟: 最後一棟可以搶，因此從假裝第一棟不存在，從第二棟開始，計算直到最後一棟時能搶的最多錢

> Q: 如果在計算**能搶第一棟**的狀況時，最終使金額最大的搶法是不搶第一棟，那會不會漏算要搶最後一棟的情況？

在**能搶第一棟**的狀況時若確實可能會漏算這種情況，但這種情況一定能在計算**不能搶第一棟**的狀況中被計算到。

## 作法

分別以 `dp1[]`、`dp2[]` 來表示**能搶第一棟**和**不能搶第一棟**的狀況，以迴圈計算，`dp1` 計算到倒數第二棟的結果、`dp2` 從第二棟開始計算到最後一棟的結果，`max(dp1[n - 1], dp2[n])` 即為答案（`n` 為給定輸入數列的長度）。

## 複雜度分析

設給定的數列長度為 $n$

- 時間複雜度 : $O(n)$
  - 第一個迴圈，從 `2` 到 `n-1` : $O(n)$
  - 第二個迴圈，從 `3` 到 `n` : $O(n)$
- 空間複雜度 : $O(n)$
  - `dp1` 大小為 `n` : $O(n)$
  - `dp2` 大小為 `n` : $O(n)$

## 程式碼

```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }

        vector<int> dp1(105, 0); // rob first
        vector<int> dp2(105, 0); // can't rob first

        dp1[0] = 0;
        dp1[1] = nums[0];
        for (int i = 2; i <= nums.size() - 1; i++) {
            int curMoney = nums[i - 1];
            dp1[i] = max(dp1[i - 1], dp1[i - 2] + curMoney);
        }

        dp2[1] = 0;
        dp2[2] = nums[1];
        for (int i = 3; i <= nums.size(); i++) {
            int curMoney = nums[i - 1];
            dp2[i] = max(dp2[i - 1], dp2[i - 2] + curMoney);
        }

        return max(dp1[nums.size() - 1], dp2[nums.size()]);
    }
};
```
