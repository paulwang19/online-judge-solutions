# LeetCode 3195 - Find the Minimum Area to Cover All Ones I

## 程式碼

```cpp
class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int minX = grid.size();
        int maxX = -1;
        int minY = grid[0].size();
        int maxY = -1;
        bool hasOne = false;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    hasOne = true;
                    minX = min(minX, i);
                    maxX = max(maxX, i);
                    minY = min(minY, j);
                    maxY = max(maxY, j);
                }
            }
        }

        if (!hasOne) {
            return 0;
        }
        
        return (maxX - minX + 1) * (maxY - minY + 1);
    }
};
```
