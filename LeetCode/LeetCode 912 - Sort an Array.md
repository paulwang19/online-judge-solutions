# LeetCode 912 - Sort an Array

## 程式碼

快速排序法，隨機取 pivot，避免最壞情況

```cpp
class Solution {
private:
    mt19937 rng{random_device{}()};

    void quicksort(vector<int>& nums, int start, int end) {
        if (start >= end) {
            return;
        }

        int r = start + rng() % (end - start);
        swap(nums[start], nums[r]);

        int pivot = nums[start];
        int i = start, j = end - 1;
        while (i < j) {
            while (i < end && nums[i] <= pivot) { // i 要往右找一個比 pivot 大的數
                i++;
            }

            while (j > start && nums[j] >= pivot) { // j 要往左找一個比 pivot 小的數
                j--;
            }

            if (i < j) {
                swap(nums[i], nums[j]);
            }
        }

        swap(nums[start], nums[j]);
        quicksort(nums, start, j);
        quicksort(nums, j + 1, end);
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        quicksort(nums, 0, nums.size());
        return nums;
    }
};
```

## 隨機數生成器

本題使用到隨機數生成器 `mt19937`，這是 C++11 提供的隨機數生成器，比起傳統的 `rand()`，它具有更好的隨機性和性能。

`random_device` 是一個從作業系統取得真隨機數的類別（Linux 上通常讀 `/dev/urandom`）。`random_device{}` 建立一個暫時物件，後面再接一個 `()` 是呼叫它的 `operator()`，會回傳一個 `unsigned int` 的隨機值。此呼叫缺點是速度慢，所以通常只用來產生一次種子。

`mt19937` 是 Mersenne Twister 演算法的偽隨機數產生器，大括號裡放的是種子，這裡以 `rng` 作為變數名稱，後續要產生隨機數時使用 `rng()` 呼叫。
