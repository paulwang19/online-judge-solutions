# LeetCode 152 - Maximum Product Subarray

## 想法

雖然這題分類在一維動態規劃，但我使用一個較技巧的想法來解。

先假設整條陣列沒有 0，若全是正數，那答案就是整條陣列的乘積；若包含偶數個負數，那答案也是整條陣列的乘積；若包含奇數個負數，那答案就是不包含第一個負數的子陣列乘積或是不包含最後一個負數的子陣列乘積。

若陣列出現 0，會讓整體答案變成 0，因此可以將陣列切成多個不包含 0 的子陣列，分別計算每個子陣列的最大乘積，最後再與 0 比較取最大值。

## 程式碼

```cpp
class Solution {
private:
    int findFirstNegative(const vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0) {
                return i;
            }
        }

        return nums.size();
    }

    int findLastNegative(const vector<int>& nums) {
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] < 0) {
                return i;
            }
        }

        return -1;
    }

    int getMaxProduct(const vector<int>& noZeroNums) {
        if (noZeroNums.size() == 1) {
            return noZeroNums[0];
        }

        int negCount = 0;
        for (int num : noZeroNums) {
            if (num < 0) {
                negCount++;
            }
        }

        if (negCount % 2 == 0) {
            int product = 1;
            for (int i = 0; i < noZeroNums.size(); i++) {
                product *= noZeroNums[i];
            }
            
            return product;
        }
        else {
            int firstProduct = 1;
            for (int i = findFirstNegative(noZeroNums) + 1; i < noZeroNums.size(); i++) {
                firstProduct *= noZeroNums[i];
            }

            int secondProduct = 1;
            for (int i = findLastNegative(noZeroNums) - 1; i >= 0; i--) {
                secondProduct *= noZeroNums[i];
            }

            return max(firstProduct, secondProduct);
        }
    }

public:
    int maxProduct(vector<int>& nums) {
        int i = 0;
        int start = 0;
        int maxProduct = INT_MIN;
        bool hasZero = false;
        while (i <= nums.size()) {
            if (i == nums.size() || nums[i] == 0 && (hasZero = true)) {
                cout << "start: " << start << ", end: " << i << endl;
                if (i - start > 0) {
                    vector<int> noZeroNums(nums.begin() + start, nums.begin() + i);
                    maxProduct = max(maxProduct, getMaxProduct(noZeroNums));
                }

                start = i + 1;
            }

            i++;
        }

        if (hasZero) {
            maxProduct = max(maxProduct, 0);
        }

        return maxProduct;
    }
};
```
