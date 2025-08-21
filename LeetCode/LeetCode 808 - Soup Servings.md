# LeetCode 808 - Soup Servings

## 程式碼

```cpp
class Solution {
private:
    map<pair<int, int>, double> probMap;

public:
    double soupServings(int n) {
        if (n > 5000) return 1.0;
        int hp = n / 25 + (n % 25 != 0); // convert mL to health point
        return calProb(hp, hp);
    }

    double calProb(int hpA, int hpB) {
        if (hpA <= 0 && hpB <= 0) {
            return 0.5;
        } else if (hpA <= 0) {
            return 1.0;
        } else if (hpB <= 0) {
            return 0.0;
        }

        map<pair<int, int>, double>::iterator it = probMap.find({hpA, hpB});
        if (it != probMap.end()) {
            return it->second;
        }

        double prob =
            0.25 * calProb(hpA - 4, hpB) + 0.25 * calProb(hpA - 3, hpB - 1) +
            0.25 * calProb(hpA - 2, hpB - 2) + 0.25 * calProb(hpA - 1, hpB - 3);
        probMap.insert({{hpA, hpB}, prob});
        return prob;
    }
};
```
