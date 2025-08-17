# LeetCode 837 - New 21 Game

## 想法

以 21 點遊戲為例子，當點數超過 17 點即不補牌，且每次補牌可能的點數為 1 ~ 10。

假設 $P(i)$ 表示剛好得到 $i$ 點的機率，目標為計算當停止補牌時（意即點數達到 17 點以上），沒有爆牌的機率為多少（意即點數未超過 21 點），因此，題意即為求出 $P(17) + P(18) + \cdots + P(21)$ 。

$P(0) = 1$ （因為初始就是 0 點），而正好得到 1 點的機率為 $\frac{1}{10} \times P(0)$ ，因為 1 點為原先 0 點的情況，然後抽到點數為 1 的牌，根據題目假設，每次抽牌的機率為均勻的，所以抽到點數 1 的牌的機率為十分之一，以此類推，我們可以得到：

$$
\begin{align*}
& P(1) = \frac{1}{10} \times P(0) \\
& P(2) = \frac{1}{10} \times (P(0) + P(1)) \\
& P(3) = \frac{1}{10} \times (P(0) + P(1) + P(2)) \\
& \vdots \\
& P(21) = \frac{1}{10} \times (P(11) + P(12) + \cdots + P(16)) \\
\end{align*}
$$

注意 $P(21)$ 的計算並非 $\frac{1}{10} \times (P(1) + P(2) + \cdots + P(20))$ ，因為點數最大可能為 10 點，因此當前點數最小可能必須為 11 點，才有可能抽一次牌後達到 21 點；另外，由於點數達到 17 點後就停止補牌了，因此也不存在當前點數為 17 ~ 20 點，然後抽一張牌達到 21 點的情況。

## 作法

輸入為 `n`、`k`、及 `maxPts`，利用 `p[i]` 表示正好達到 `i` 點的機率，初始 `p[0] = 1.0`，對於每個 `1 ~ n` 的點數 `i`，利用 `p[i] = (p[i - maxPts] + ... + p[i - 2] + p[i - 1]) / maxPts` 來計算，其中 `i - 1` 必須小於 `k`。

若每個 `i` 都重新累加一次機率，終將獲得 TLE，因此觀察規律，使用更有效率的計算方式 - 滑動窗格 (Sliding Window)。

使用一個 queue 來維護這個窗格內的元素、`windowSum` 來儲存窗格內累加結果、以及 `stopDrawProbSum` 累加停止補牌後的機率總和（即我們要求的答案）。

對於每次計算 `p[i]` 的步驟為 :

- 剛好得到 `i` 分的機率 `curProb = windowSum / maxPts`
- 若 `i` < `k`，可以繼續抽牌，因此將當前機率累加至 `windowSum`
- 若 `i` >= `k`，停止補牌，將當前機率累加至 `stopDrawProbSum`
- 窗格大小上限為 `maxPts - 1` （因為目標 `i` 點只有 `i - maxPts` ~ `i - 1` 點能夠抽一張牌達到），當 `i >= maxPts` 時，從 queue 和 `windowSum` 中移除窗格內最舊的機率元素。

對於 `i` 從 `1` 到 `n`，重複以上步驟，`stopDrawProbSum` 即為答案。

當 `k = 0` 時（即未補牌前即停止補牌），由於沒有爆點，因此答案應為 `1.0`，此為特殊 case，需要特別處理。

## 複雜度分析

- 時間複雜度 : $O(n)$
- 空間複雜度 : $O(maxPts)$

## 程式碼

```cpp
class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if (k == 0 || n - maxPts > k) {
            return 1.0;
        }

        queue<double> slidingWindow;
        double windowSum = 0.0;
        double stopDrawProbSum = 0.0;
        slidingWindow.push(1.0);
        windowSum += slidingWindow.front();
        for (int i = 1; i <= n; i++) {
            double curProb = windowSum / maxPts;
            if (i < k) {
                slidingWindow.push(curProb);
                windowSum += curProb;
            }
            else {
                stopDrawProbSum += curProb;
            }

            if (i >= maxPts) {
                windowSum -= slidingWindow.front();
                slidingWindow.pop();
            }
        }

        return stopDrawProbSum;
    }
};
```

## 參考

- <https://leetcode.com/problems/new-21-game/solutions/7090539/new-21-game-100-beat-most-efficient-java-c-python-c-c-go-javascript-tyscript/?envType=daily-question&envId=2025-08-17>
- <https://www.cnblogs.com/grandyang/p/10386525.html>
