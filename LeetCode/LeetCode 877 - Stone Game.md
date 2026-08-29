# LeetCode 877 - Stone Game

## 程式碼

`dp` 存 Alice 扣掉 Bob 的分數，`dp[i][j]` 代表第 `i` 堆到第 `j` 堆石頭這個範圍所能得到的最大分數。

```cpp
class Solution {
private:
    vector<vector<int>> dp = vector<vector<int>>(500, vector<int>(500, INT_MIN));

    int findAliceMaxPoint(const vector<int>& piles, int i, int j) {
        if (dp[i][j] != INT_MIN) {
            return dp[i][j];
        }

        if (i == j) {
            dp[i][j] = piles[i];
            return dp[i][j];
        }

        int turn = (j - i) % 2;
        if (turn == 0) {  // Alice's turn
            dp[i][j] = max(findAliceMaxPoint(piles, i + 1, j) + piles[i],
                           findAliceMaxPoint(piles, i, j - 1) + piles[j]);
        }
        else {
            dp[i][j] = max(findAliceMaxPoint(piles, i + 1, j) - piles[i],
                           findAliceMaxPoint(piles, i, j - 1) - piles[j]);
        }

        return dp[i][j];
    }

public:
    bool stoneGame(vector<int>& piles) {
        return findAliceMaxPoint(piles, 0, piles.size() - 1) > 0;
    }
};
```
