# LeetCode 611 - Valid Triangle Number

## 程式碼

```cpp
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        vector<int> positiveNums;
        for (int i = 0; i < nums.size(); i++) {
            if (nums.at(i) > 0) {
                positiveNums.push_back(nums.at(i));
            }
        }

        sort(positiveNums.begin(), positiveNums.end());
        int triangleCount = 0;
        for (int i = 0; i < positiveNums.size(); i++) {
            vector<int>::iterator maxLimitIt = positiveNums.begin() + i + 2;
            for (int j = i + 1; j < positiveNums.size(); j++) {
                maxLimitIt = lower_bound(maxLimitIt, positiveNums.end(), positiveNums.at(i) + positiveNums.at(j));
                int k = distance(positiveNums.begin(), maxLimitIt);
                triangleCount += k - j - 1;
            }
        }

        return triangleCount;
    }
};
```
