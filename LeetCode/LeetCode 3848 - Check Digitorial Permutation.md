# LeetCode 3848 - Check Digitorial Permutation

## 程式碼

```cpp
class Solution {
public:
    void findUsedDigit(int n, vector<int> &digitCount) {
        digitCount.assign(10, 0);
        
        int curNum = n;
        while (curNum > 0) {
            digitCount[curNum % 10]++;
            curNum /= 10;
        }
    }
    
    bool isDigitorialPermutation(int n) {
        vector<int> factorials(10, 0);
        factorials[0] = 1;
        for (int i = 1; i < factorials.size(); i++) {
            factorials[i] = factorials[i - 1] * i;
        }

        int curNum = n;
        int curSum = 0;
        while (curNum > 0) {
            curSum += factorials[curNum % 10];
            curNum /= 10;
        }

        vector<int> targetUsedDigitCount;
        vector<int> facSumUsedDigitCount;
        findUsedDigit(n, targetUsedDigitCount);
        findUsedDigit(curSum, facSumUsedDigitCount);

        for (int i = 0; i < targetUsedDigitCount.size(); i++) {
            if (targetUsedDigitCount[i] != facSumUsedDigitCount[i]) {
                return false;
            }
        }
        
        return true;
    }
};
```
