# LeetCode 91 - Decode Ways

## 程式碼

```cpp
class Solution {
public:
    int numDecodings(string s) {
        if (s.length() == 0 || s[0] == '0') return 0;
        if (s.length() == 1) return 1;

        vector<int> dp(s.length() + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i < dp.size(); i++) {
            int curDigit = s[i - 1] - '0';
            int prevDigit = s[i - 2] - '0';
            if (curDigit >= 1 && curDigit <= 9) {
                dp[i] += dp[i - 1];
            }
            if (prevDigit != 0 && prevDigit * 10 + curDigit >= 1 && prevDigit * 10 + curDigit <= 26) {
                dp[i] += dp[i - 2];
            }
        }
        
        return dp[s.length()];
    }
};
```
