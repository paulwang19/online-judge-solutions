# LeetCode 242 - Valid Anagram

## 程式碼

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> sCount(26, 0);
        vector<int> tCount(26, 0);
        for (char ch : s) {
            sCount[ch - 'a']++;
        }
        for (char ch : t) {
            tCount[ch - 'a']++;
        }

        return sCount == tCount;
    }
};
```
