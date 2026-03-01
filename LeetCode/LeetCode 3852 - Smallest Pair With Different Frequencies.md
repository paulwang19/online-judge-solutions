# LeetCode 3852 - Smallest Pair With Different Frequencies

## 程式碼

```cpp
class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        map<int, int> numFreqMap;
        for (int num : nums) {
            if (numFreqMap.find(num) == numFreqMap.end()) {
                numFreqMap[num] = 1;
            }
            else {
                numFreqMap[num]++;
            }
        }

        for (auto first = numFreqMap.begin(); first != numFreqMap.end(); first++) {
            for (auto second = first; second != numFreqMap.end(); second++) {
                if (first == second) continue;
                if (first->second != second->second) {
                    return {first->first, second->first};
                }
            }
        }

        return {-1, -1};
    }
};
```
