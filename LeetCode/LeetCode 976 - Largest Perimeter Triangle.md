# LeetCode 976 - Largest Perimeter Triangle

## 想法

給定三個數字 `a`, `b`, `c`，假設 `c` 為最大值，則當 `a + b > c` 時，`a`, `b`, `c` 能形成三角形

將陣列由小至大排序後，為了找出最大周長的三角形，我們從最大的數字開始挑選並作為最長邊 `c`，再挑選第二、第三大的數字做為 `a`, `b`，檢查 `a`, `b` 能否與 `c` 形成三角形，此時會有以下兩種情況

- `a`, `b` 能與 `c` 形成三角形: 由於 `a`, `b`, `c` 是目前最大的三個數字，因此 `a + b + c` 必為最大周長，直接回傳 `a + b + c`
- `a`, `b` 不能與 `c` 形成三角形: 說明 `a + b > c` 不成立，且挑選其他數字做為 `a`, `b` 也無意義，因為其他數字都比 `a`, `b` 小，因此加總起來必定也比 `c` 小，說明最大的三角形，其最長邊不會是 `c`，因此捨棄原先選擇的數字，繼續往前挑選第二大數字做為新的 `c`，並重複上述檢查過程

## 程式碼

```cpp
class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = nums.size() - 1; i >= 2; i--) {
            if (nums.at(i - 2) + nums.at(i - 1) > nums.at(i)) {
                return nums.at(i - 2) + nums.at(i - 1) + nums.at(i);
            }
        }

        return 0;
    }
};
```
