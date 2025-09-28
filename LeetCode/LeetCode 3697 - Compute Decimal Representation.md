# LeetCode 3697 - Compute Decimal Representation

## 程式碼

```cpp
class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        deque<int> container;
        long long p = 1;
        while (n > 0) {
            int d = n % 10;
            d *= p;
            if (d > 0) {
                container.push_front(d);
            }
            
            p *= 10;
            n /= 10;
        }

        return vector<int>(container.begin(), container.end());
    }
};
```
