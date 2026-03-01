# LeetCode 3853 - Merge Close Characters

## 程式碼

```cpp
class Solution {
public:
    string mergeCharacters(string s, int k) {
        int i = 0;
        while (i < s.length()) {
            char curCh = s[i];
            string compareStr = s.substr(i + 1, k);
            size_t relativeIndex = compareStr.find(curCh);
            if (relativeIndex == string::npos) {
                i++;
            }
            else {
                s.erase(i + 1 + relativeIndex, 1);
                i = 0;
            }
        }

        return s;
    }
};
```
