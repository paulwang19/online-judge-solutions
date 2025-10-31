# LeetCode 217 - Contains Duplicate

## 程式碼

```cpp
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hash;
        for (int i = 0; i < nums.size(); i++) {
            if (hash.find(nums.at(i)) != hash.end()) {
                return true;
            }

            hash.insert(nums.at(i));
        }

        return false;
    }
};
```
