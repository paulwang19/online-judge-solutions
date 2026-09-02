# LeetCode 1406 - Stone Game III

## 程式碼

```cpp
class Solution {
private:
    vector<int> dp = vector<int>(50000, INT_MIN);
    vector<int> stoneValueSum = vector<int>(50001, 0);

    int findPlayerMaxPoint(const vector<int>& stoneValue, int startIndex) {
        if (startIndex >= stoneValue.size()) {
            return 0;
        }

        if (dp[startIndex] != INT_MIN) {
            return dp[startIndex];
        }

        int result = INT_MIN;
        for (int i = 1; i <= 3 && startIndex + i <= stoneValue.size(); i++) {
            result = max(result, stoneValueSum[startIndex] - findPlayerMaxPoint(stoneValue, startIndex + i));
        }

        return dp[startIndex] = result;
    }

public:
    string stoneGameIII(vector<int>& stoneValue) {
        stoneValueSum[stoneValue.size()] = 0;
        for (int i = stoneValue.size() - 1; i >= 0; i--) {
            stoneValueSum[i] = stoneValueSum[i + 1] + stoneValue[i];
        }

        int alicePoint = findPlayerMaxPoint(stoneValue, 0);
        int bobPoint = stoneValueSum[0] - alicePoint;
        if (alicePoint > bobPoint) {
            return "Alice";
        }
        else if (alicePoint < bobPoint) {
            return "Bob";
        }
        else {
            return "Tie";
        }
    }
};
```
