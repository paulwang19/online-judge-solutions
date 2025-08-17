# LeetCode 3 - Longest Substring Without Repeating Characters

## 程式碼

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0;
        int end = 1;
        int lenOfMax = s.length() > 0 ? 1 : 0;
        while (end < s.length()) {
            if (s.substr(start, end - start).find(s[end]) ==
                std::string::npos) {
                end++;
                if (lenOfMax < end - start) {
                    lenOfMax = end - start;
                } // if
            } // if
            else {
                start++;
            } // else
        } // while

        return lenOfMax;
    }
};
```
