# LeetCode 3005 - Count Elements With Maximum Frequency

## 程式碼

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function maxFrequencyElements($nums) {
        $numFreqs = array_fill(1, 100, 0);
        $maxFreq = 0;
        foreach ($nums as $num) {
            $numFreqs[$num]++;
            if ($numFreqs[$num] > $maxFreq) {
                $maxFreq = $numFreqs[$num];
            }
        }

        $maxFreqCount = 0;
        foreach ($numFreqs as $freq) {
            if ($freq === $maxFreq) {
                $maxFreqCount++;
            }
        }

        return $maxFreq * $maxFreqCount;
    }
}
```
