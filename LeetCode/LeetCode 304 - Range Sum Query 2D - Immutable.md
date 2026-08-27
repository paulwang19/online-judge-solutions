# LeetCode 304 - Range Sum Query 2D - Immutable

## 程式碼

```cpp
class NumMatrix {
private:
    vector<vector<int>> rectangleSumMatrix = vector<vector<int>>(200, vector<int>(200, 0));

public:
    NumMatrix(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                rectangleSumMatrix[i][j] = matrix[i][j];
                if (i > 0 && j > 0) {
                    rectangleSumMatrix[i][j] -= rectangleSumMatrix[i - 1][j - 1];
                }

                if (i > 0) {
                    rectangleSumMatrix[i][j] += rectangleSumMatrix[i - 1][j];
                }

                if (j > 0) {
                    rectangleSumMatrix[i][j] += rectangleSumMatrix[i][j - 1];
                }
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = rectangleSumMatrix[row2][col2];
        if (row1 > 0) {
            sum -= rectangleSumMatrix[row1 - 1][col2];
        }

        if (col1 > 0) {
            sum -= rectangleSumMatrix[row2][col1 - 1];
        }

        if (row1 > 0 && col1 > 0) {
            sum += rectangleSumMatrix[row1 - 1][col1 - 1];
        }

        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
```
