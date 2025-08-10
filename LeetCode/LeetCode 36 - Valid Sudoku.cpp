class Solution {
private:
    int rowCnt[9][10] = {0};
    int colCnt[9][10] = {0};
    int boxCnt[9][10] = {0};

public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            vector<char>& line = board.at(i);
            for (int j = 0; j < line.size(); j++) {
                int gridNum = getGridNum(line.at(j));
                if (gridNum != -1) {
                    int boxArea = getBoxArea(i, j);
                    rowCnt[i][gridNum] += 1;
                    colCnt[j][gridNum] += 1;
                    boxCnt[boxArea][gridNum] += 1;
                    if (rowCnt[i][gridNum] > 1 || colCnt[j][gridNum] > 1 ||
                        boxCnt[boxArea][gridNum] > 1) {
                        return false;
                    }
                }
            }
        }

        return true;
    }

    int getGridNum(char ch) {
        if (ch >= '0' && ch <= '9') {
            return ch - '0';
        }

        return -1;
    }

    int getBoxArea(int i, int j) { return i / 3 * 3 + j / 3; }
};