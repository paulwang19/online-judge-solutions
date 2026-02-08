# LeetCode 49 - Group Anagrams

## 程式碼

```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> groups;
        int nextIndex = 0;
        unordered_map<string, int> anagramsIndexMap;
        for (string str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            if (anagramsIndexMap.find(key) == anagramsIndexMap.end()) {
                vector<string> group = {str};
                groups.push_back(group);

                anagramsIndexMap[key] = nextIndex;
                nextIndex += 1;
            }
            else {
                int index = anagramsIndexMap[key];
                groups[index].push_back(str);
            }
        }

        return groups;
    }
};
```
