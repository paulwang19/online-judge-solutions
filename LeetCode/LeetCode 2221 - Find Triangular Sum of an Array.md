# LeetCode 2221 - Find Triangular Sum of an Array

## 程式碼

```cpp
class Solution {
public:
    int triangularSum(vector<int>& nums) {
        vector<int> tempArray(nums.begin(), nums.end());
        for (int n = tempArray.size(); n >= 1; n--) {
            for (int i = 0; i < n - 1; i++) {
                tempArray.at(i) = (tempArray.at(i) + tempArray.at(i + 1)) % 10;
            }
        }

        return tempArray.at(0);
    }
};
```
