# LeetCode 1140 - Stone Game II

## 想法

此題只能從最前面拿取石頭，所以 `dp` 使用一個維度儲存從第幾個開始拿到最後的最大分數就可以，另一個維度儲存目前的 `M` 值

當前這個玩家在第 `i` 個石頭開始拿，且目前的 `M` 值為 `m` 時所能獲得的最大石頭數，就是從第 `i` 個石頭開始算到最後的總和，扣掉輪到下個玩家移動時可能拿到的最大石頭數

## 程式碼

```cpp
class Solution {
private:
    vector<vector<int>> dp = vector<vector<int>>(101, vector<int>(128, INT_MIN));
    vector<int> pilesSum = vector<int>(101, 0);

    int findPlayerMaxPoint(const vector<int>& piles, int i, int m) {
        if (dp[i][m] != INT_MIN) {
            return dp[i][m];
        }

        if (i + m * 2 >= piles.size()) {
            return dp[i][m] = pilesSum[i];
        }

        int res = INT_MIN;
        for (int x = 1; x <= m * 2; x++) {
            res = max(res, pilesSum[i] - findPlayerMaxPoint(piles, i + x, max(x, m)));
        }

        return dp[i][m] = res;
    }

public:
    int stoneGameII(vector<int>& piles) {
        pilesSum[piles.size()] = 0;
        for (int i = piles.size() - 1; i >= 0; i--) {
            pilesSum[i] = pilesSum[i + 1] + piles[i];
        }
        return findPlayerMaxPoint(piles, 0, 1);
    }
};
```
