# LeetCode 1689 - Partitioning Into Minimum Number Of Deci-Binary Numbers

## 程式碼

```cpp
class Solution {
public:
    int minPartitions(string n) {
        int maxDigit = 0;
        for (char digit : n) {
            if (maxDigit < digit - '0') {
                maxDigit = digit - '0';
            }
        }

        return maxDigit;
    }
};
```
