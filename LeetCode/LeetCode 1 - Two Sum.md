# LeetCode 1 - Two Sum

## 程式碼

### 暴力解

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums.at(i) + nums.at(j) == target) {
                    ans.push_back(i);
                    ans.push_back(j);
                }
            }
        }

        return ans;
    }
};
```

### One-Pass 雜湊表解法

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> hashTable;
        for (int i = 0; i < nums.size(); i++) {
            int findNum = target - nums[i];
            unordered_map<int, int>::iterator it = hashTable.find(findNum);
            if (it != hashTable.end()) {
                ans.push_back(it->second);
                ans.push_back(i);
                break;
            }

            hashTable.insert({nums[i], i});
        }

        return ans;
    }
};
```
