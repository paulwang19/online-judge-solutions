# LeetCode 3843 - First Element with Unique Frequency

## 程式碼

```cpp
class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        vector<int> numsFreq(100005, 0);
        for (int num : nums) {
            numsFreq[num]++;
        }

        map<int, vector<int>> freqNumsMap;
        for (int i = 1; i <= 100000; i++) {
            int freq = numsFreq[i];
            if (freq > 0) {
                if (freqNumsMap.find(freq) == freqNumsMap.end()) {
                    freqNumsMap.insert({freq, {i}});
                }
                else {
                    freqNumsMap.find(freq)->second.push_back(i);
                }
            }
        }

        set<int> uniqueFreqSet;
        for (map<int, vector<int>>::iterator it = freqNumsMap.begin(); it != freqNumsMap.end(); it++) {
            if (it->second.size() == 1) {
                uniqueFreqSet.insert(it->first);
            }
        }

        if (uniqueFreqSet.empty()) {
            return -1;
        }

        for (int num : nums) {
            int freq = numsFreq[num];
            if (uniqueFreqSet.find(freq) != uniqueFreqSet.end()) {
                return num;
            }
        }

        return 0;
    }
};
```
