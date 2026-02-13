# LeetCode 75 - Sort Colors

## 程式碼

```c
void sortColors(int* nums, int numsSize) {
    int numsFreq[3] = {0};
    for (int i = 0; i < numsSize; i++) {
        numsFreq[nums[i]]++;
    }

    int index = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < numsFreq[i]; j++) {
            nums[index] = i;
            index++;
        }
    }
}
```
