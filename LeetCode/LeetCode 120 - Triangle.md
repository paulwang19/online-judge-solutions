# LeetCode 120 - Triangle

## 程式碼

```cpp
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp(triangle.rbegin()->size() + 1, 0);
        for (int r = triangle.size() - 1; r >= 0; r--) {
            for (int i = 0; i < triangle.at(r).size(); i++) {
                int currentValue = triangle.at(r).at(i);
                int minTotal = dp.at(i) < dp.at(i + 1) ? dp.at(i) : dp.at(i + 1);
                dp.at(i) = currentValue + minTotal;
            }
        }

        return dp.at(0);
    }
};
```
