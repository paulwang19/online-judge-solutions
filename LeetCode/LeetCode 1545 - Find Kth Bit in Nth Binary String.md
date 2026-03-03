# LeetCode 1545 - Find Kth Bit in Nth Binary String

## 程式碼

```cpp
class Solution {
public:
    char digitToChar(int d) {
        return '0' + d;
    }

    char recursiveFindKthBit(int n, int k, bool reverseMid = false) {
        if (n == 1) {
            return digitToChar(0 ^ reverseMid);
        }

        int mid = pow(2, n - 1);
        if (k == mid) {
            return digitToChar(1 ^ reverseMid);
        }
        else if (k < mid) {
            return recursiveFindKthBit(n - 1, k);
        }
        else {
            return recursiveFindKthBit(n - 1, k - mid, true);
        }
    }

    char findKthBit(int n, int k) {
        return recursiveFindKthBit(n, k);
    }
};
```
