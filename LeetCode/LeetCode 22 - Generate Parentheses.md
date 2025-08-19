# LeetCode 22 - Generate Parentheses

## 程式碼

```cpp
class Solution {
private:
    vector<string> result;

public:
    vector<string> generateParenthesis(int n) {
        char *buffer = new char[n * 2 + 1];
        buffer[n * 2] = '\0';
        generateParenthesis(buffer, 0, n, n);
        return result;
    }

    void generateParenthesis(char* buffer, int currentPos, int openLeftCount, int closeLeftCount) {
        if (openLeftCount == 0 && closeLeftCount == 0) {
            result.push_back(string(buffer));
            return;
        } else if (openLeftCount > closeLeftCount) {
            return;
        }

        if (openLeftCount > 0) {
            buffer[currentPos] = '(';
            generateParenthesis(buffer, currentPos + 1, openLeftCount - 1, closeLeftCount);
        }

        buffer[currentPos] = ')';
        generateParenthesis(buffer, currentPos + 1, openLeftCount, closeLeftCount - 1);
    }
};
```
