# LeetCode 778 - Swim in Rising Water

## 程式碼

```cpp
struct Grid {
    int x;
    int y;
    int value;
};

struct GridLessComparator {
    bool operator()(Grid& a, Grid& b) const { return a.value > b.value; }
};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> mark(n, vector<bool>(n, false));
        priority_queue<Grid, vector<Grid>, GridLessComparator> pq;
        int curLevel = 0;

        pq.push({0, 0, grid.at(0).at(0)});
        while (!mark.at(n - 1).at(n - 1)) {
            while (!pq.empty() && pq.top().value <= curLevel) {
                Grid curGrid = pq.top();
                pq.pop();
                if (mark.at(curGrid.x).at(curGrid.y)) {
                    continue;
                }
                else {
                    mark.at(curGrid.x).at(curGrid.y) = true;
                    if (curGrid.y < grid.size() - 1 && !mark.at(curGrid.x).at(curGrid.y + 1)) {
                        pq.push({curGrid.x, curGrid.y + 1,
                                 grid.at(curGrid.x).at(curGrid.y + 1)});
                    }
                    if (curGrid.x < grid.size() - 1 && !mark.at(curGrid.x + 1).at(curGrid.y)) {
                        pq.push({curGrid.x + 1, curGrid.y,
                                 grid.at(curGrid.x + 1).at(curGrid.y)});
                    }
                    if (curGrid.y > 0 && !mark.at(curGrid.x).at(curGrid.y - 1)) {
                        pq.push({curGrid.x, curGrid.y - 1,
                                 grid.at(curGrid.x).at(curGrid.y - 1)});
                    }
                    if (curGrid.x > 0 && !mark.at(curGrid.x - 1).at(curGrid.y)) {
                        pq.push({curGrid.x + -1, curGrid.y,
                                 grid.at(curGrid.x - 1).at(curGrid.y)});
                    }
                }
            }

            curLevel += 1;
        }

        return curLevel - 1;
    }
};
```
