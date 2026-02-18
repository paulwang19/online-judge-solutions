# LeetCode 3842 - Toggle Light Bulbs

## 程式碼

```cpp
class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<bool> isLightBlubs(101, 0);
        for (int bulbNum : bulbs) {
            isLightBlubs[bulbNum] = !isLightBlubs[bulbNum];
        }

        vector<int> lightBulb;
        for (int i = 1; i <= 100; i++) {
            if (isLightBlubs[i]) {
                lightBulb.push_back(i);
            }
        }

        return lightBulb;
    }
};
```
