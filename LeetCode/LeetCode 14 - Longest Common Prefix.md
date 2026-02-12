# LeetCode 14 - Longest Common Prefix

## 程式碼

針對所有字串，每次多取一個字元作為子字串丟進 set，並比較 set 中新增的元素是否超過 1 個
若沒超過則表示該字元是所有字串的共同子字串，將字元加進目前累積的前綴字串；若超過則共同子字串結束，回傳當前累積的前綴字串

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int minLength = 200;
        for (string s : strs) {
            if (s.length() < minLength) {
                minLength = s.length();
            }
        }

        string lcp;
        unordered_set<string> prefixSet;
        for (int r = 1; r <= minLength; r++) {
            for (string s : strs) {
                prefixSet.insert(s.substr(0, r));
            }

            if (prefixSet.size() == r) {
                lcp += strs[0][r - 1];
            }
            else {
                break;
            }
        }

        return lcp;
    }
};
```

看了其他人的解法後，發現有一種更有效率的做法
首先將所有字串排序，這樣就只需要比較第一個字串和最後一個字串就好。因為排序後的第一個字串和最後一個字串的共同前綴字串一定是所有字串的共同前綴字串。

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string firstStr = strs[0];
        string lastStr = strs[strs.size() - 1];
        int minLen = min(firstStr.length(), lastStr.length());
        for (int i = 0; i < minLen; i++) {
            if (firstStr[i] != lastStr[i]) {
                return firstStr.substr(0, i);
            }
        }

        return firstStr.substr(0, minLen);
    }
};
```
