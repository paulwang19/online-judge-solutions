# LeetCode 139 - Word Break

## 想法

暴力窮舉當前字串的開頭是否 match 字典中的單字，如果 metch 就繼續遞迴往下做。

以上做法的問題是，如果字典中的單字有很多互相包含的子字串，會造成很多重複的遞迴比對，導致時間複雜度變得很高。因此，使用記憶化遞迴，將比對過確定無法成功的 `s` 字串記錄下來，避免重複比對。

## 程式碼

```cpp
class Solution {
private:
    map<string, bool> memo;

    bool canBreak(string s, const vector<string>& wordDict) {
        if (s.empty()) {
            return true;
        }

        if (memo.find(s) != memo.end()) {
            return memo[s];
        }

        for (string word : wordDict) {
            int wordLen = word.length();
            if (s.substr(0, wordLen) == word) {
                if (canBreak(s.substr(wordLen), wordDict)) {
                    return true;
                }
            }
        }

        memo[s] = false;
        return false;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        return canBreak(s, wordDict);
    }
};
```
