# LeetCode 3854 - Minimum Operations to Make Array Parity Alternating

## 程式碼

```cpp
class Solution {
public:
    int getDiff(vector<int>& nums, bool expectFirstParity) {
        vector<int> tempNums(nums);
        int maxNum = -1e9;
        int minNum = 1e9;
        for (int num : tempNums) {
            maxNum = maxNum > num ? maxNum : num;
            minNum = minNum < num ? minNum : num; 
        }

        bool expectParity = expectFirstParity;
        for (int &num : tempNums) {
            bool targetParity = abs(num) % 2 == 1;
            if (targetParity != expectParity) {
                if (num == maxNum) num--;
                else if (num == minNum) num++;
            }

            expectParity = !expectParity;
        }

        maxNum = -1e9;
        minNum = 1e9;
        for (int num : tempNums) {
            maxNum = maxNum > num ? maxNum : num;
            minNum = minNum < num ? minNum : num; 
        }

        return maxNum - minNum;
    }

    vector<int> makeParityAlternating(vector<int>& nums) {
        vector<int> ans(2, 0);
        int firstOddOperationCount = 0;
        int firstEvenOperationCount = 0;
        bool expectParity = true;
        for (int num : nums) {
            bool targetParity = abs(num) % 2 == 1;
            targetParity == expectParity ? ++firstEvenOperationCount : ++firstOddOperationCount;
            expectParity = !expectParity;
        }

        if (firstOddOperationCount < firstEvenOperationCount) {
            ans[0] = firstOddOperationCount;
            ans[1] = getDiff(nums, true);
        }
        else if (firstOddOperationCount > firstEvenOperationCount) {
            ans[0] = firstEvenOperationCount;
            ans[1] = getDiff(nums, false);
        }
        else {
            ans[0] = firstOddOperationCount;
            ans[1] = min(getDiff(nums, true), getDiff(nums, false));
        }

        return ans;
    }
};
```
