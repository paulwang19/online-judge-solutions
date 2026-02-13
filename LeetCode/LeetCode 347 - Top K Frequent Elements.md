# LeetCode 347 - Top K Frequent Elements

## 程式碼

```cpp
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> offsetNumFreq(20005, 0);
        const int OFFSET = 10000;
        for (int num : nums) {
            offsetNumFreq[num + OFFSET]++;
        }

        map<int, vector<int>, greater<int>> freqNumMap;
        for (int i = 0; i < offsetNumFreq.size(); i++) {
            int freq = offsetNumFreq[i];
            if (freq > 0) {
                map<int, vector<int>>::iterator it = freqNumMap.find(freq);
                if (it == freqNumMap.end()) {
                    vector<int> target = {i - OFFSET};
                    freqNumMap.insert({freq, target});
                }
                else {
                    it->second.push_back(i - OFFSET);
                }
            }
        }

        map<int, vector<int>>::iterator walk = freqNumMap.begin();
        vector<int> elements;
        while (elements.size() < k && walk != freqNumMap.end()) {
            vector<int> target = walk->second;
            elements.insert(elements.end(), target.begin(), target.end());
            walk++;
        }

        return elements;
    }
};
```
