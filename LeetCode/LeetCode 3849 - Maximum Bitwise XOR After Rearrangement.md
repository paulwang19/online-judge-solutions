# LeetCode 3849 - Maximum Bitwise XOR After Rearrangement

## 程式碼

```cpp
class Solution {
public:
    string maximumXor(string s, string t) {
        vector<int> digitCount(2, 0);
        for (char ch : t) {
            digitCount[ch == '1']++;
        }

        string curStr = "";
        for (char ch : s) {
            int d = ch - '0';
            if (digitCount[d ^ 1] > 0) {
                digitCount[d ^ 1]--;
                curStr += "1";
            }
            else {
                digitCount[d]--;
                curStr += "0";
            }
        }
        
        return curStr;
    }
};
```
