# LeetCode 3847 - Find the Score Difference in a Game

## 程式碼

```cpp
class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        vector<int> score(2, 0);
        int activePlayer = 0;
        for (int i = 0; i < nums.size(); i++) {
            activePlayer ^= nums[i] & 1;
            if ((i + 1) % 6 == 0) {
                activePlayer ^= 1;
            }

            score[activePlayer] += nums[i];
        }

        return score[0] - score[1];
    }
};
```
