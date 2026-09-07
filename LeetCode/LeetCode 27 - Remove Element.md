# LeetCode 27 - Remove Element

## 程式碼

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int notEqualCount = nums.size();
        while (i < nums.size()) {
            if (nums[i] == val) {
                nums.erase(nums.begin() + i);
                notEqualCount--;
            }
            else {
                i++;
            }
        }

        return notEqualCount;
    }
};
```
