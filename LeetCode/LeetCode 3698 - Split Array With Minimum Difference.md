# LeetCode 3698 - Split Array With Minimum Difference

## 想法

這是一個找出從哪些點分割陣列，能使得左子陣列符合嚴格遞增、右子陣列符合嚴格遞減，並從這些點挑出使得兩子陣列和的差值最小的分割點的問題

### 暴力法

如果一一找尋所有可能的分割點，並計算子陣列和的差值，將使得時間複雜度達到 $O(n^2)$

### 預先計算法

我們可以預先計算哪些位置為**嚴格遞增前綴**、哪些位置為**嚴格遞減後綴**，並預先計算每個位置的**前綴和**，如此一來，找到可能的分割點後，利用該分割點前綴和以及總和減去該分割點前綴和即可分別得到左子陣列以及右子陣列的和，時間複雜度降為 $O(n)$

## 作法

總共分成 3 個步驟

1. 預先計算嚴格遞增前綴、嚴格遞減後綴、及前綴和:
    - 計算嚴格遞增前綴: 使用布林陣列 `isIncreasingPrefix`，如果 `isIncreasingPrefix[i]` 為 `true`，則表示 `nums[0] ~ nums[i]` 為嚴格遞增
    - 計算嚴格遞減後綴: 使用布林陣列 `isDecreasingSuffix`，如果 `isDecreasingSuffix[i]` 為 `true`，則表示 `nums[i] ~ nums[n - 1]` 為嚴格遞減
    - 計算前綴和: 使用陣列 `prefixSum`，其中 `prefixSum[i]` 為 `nums[0] ~ nums[i]` 的和
2. 找出所有合法分割點: 
    - 對於一個合法分割點 `i`，能使 `nums[0] ~ nums[i]` 為嚴格遞增且 `nums[i] ~ nums[n - 1]` 為嚴格遞減，即找出 `isIncreasingPrefix[i]` 及 `isDecreasingSuffix[i + 1]` 同時為 `true` 的 `i`
    - 若找不到合法分割點，則回傳 `-1`
3. 計算所有合法分割點的子陣列和差值，並回傳最小值:
    - 左子陣列和為 `prefixSum[i]`
    - 右子陣列和為 `prefixSum[n - 1] - prefixSum[i]`

## 複雜度分析

- 時間複雜度: $O(n)$
  - 計算嚴格遞增前綴: `n - 1` 次比較，$O(n)$
  - 計算嚴格遞減後綴: `n - 1` 次比較，$O(n)$
  - 計算前綴和: `n` 次累加，$O(n)$
  - 找出合法分割點: `n - 1` 次比較，$O(n)$
  - 計算子陣列和差值: 最多 `n - 1` 次計算，$O(n)$
    - 計算左子陣列和: `1` 次計算，$O(1)$
    - 計算右子陣列和: `1` 次計算，$O(1)$
    - 計算子陣列和差值: `1` 次計算，$O(1)$
- 空間複雜度: $O(n)$
  - 嚴格遞增前綴: `n` 個整數陣列，$O(n)$
  - 嚴格遞減後綴: `n` 個整數陣列，$O(n)$
  - 前綴和: `n` 個整數陣列，$O(n)$
  - 合法分割點: 最多 `n - 1` 個整數陣列，$O(n)$
  - 子陣列和差值: 最多 `n - 1` 個整數陣列，$O(n)$

## 程式碼

```cpp
class Solution {
public:
    long long splitArray(vector<int>& nums) {
        vector<bool> isIncreasingPrefix(nums.size(), false);
        vector<bool> isDecreasingSuffix(nums.size(), false);
        vector<long long> prefixSum(nums.size(), 0);
        vector<int> splitIndices;
        vector<long long> absDiffs;

        isIncreasingPrefix.at(0) = true;
        for (int i = 1; i < nums.size(); i++) {
            if (nums.at(i - 1) >= nums.at(i)) {
                break;
            }

            isIncreasingPrefix.at(i) = true;
        }

        isDecreasingSuffix.at(nums.size() - 1) = true;
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums.at(i) <= nums.at(i + 1)) {
                break;
            }

            isDecreasingSuffix.at(i) = true;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!isIncreasingPrefix.at(i) && !isDecreasingSuffix.at(i)) {
                return -1;
            }
        }

        prefixSum.at(0) = nums.at(0);
        for (int i = 1; i < nums.size(); i++) {
            prefixSum.at(i) = prefixSum.at(i - 1) + nums.at(i);
        }

        for (int i = 0; i < nums.size() - 1; i++) {
            if (isIncreasingPrefix.at(i) && isDecreasingSuffix.at(i + 1)) {
                splitIndices.push_back(i);
            }
        }

        for (int i = 0; i < splitIndices.size(); i++) {
            int splitIndex = splitIndices.at(i);
            long long leftSum = prefixSum.at(splitIndex);
            long long rightSum = prefixSum.at(prefixSum.size() - 1) - prefixSum.at(splitIndex);
            absDiffs.push_back(abs(leftSum - rightSum));
        }

        long long minDiff = absDiffs.at(0);
        for (int i = 1; i < absDiffs.size(); i++) {
            minDiff = minDiff <= absDiffs.at(i) ? minDiff : absDiffs.at(i);
        }

        return minDiff;
    }
};
```
