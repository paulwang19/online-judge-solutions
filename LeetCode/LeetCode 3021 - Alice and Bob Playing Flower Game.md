# LeetCode 3021 - Alice and Bob Playing Flower Game

## 程式碼

```php
class Solution {

    /**
     * @param Integer $n
     * @param Integer $m
     * @return Integer
     */
    function flowerGame($n, $m) {
        return $this->getOddCount($n) * $this->getEvenCount($m) +
               $this->getEvenCount($n) * $this->getOddCount($m);
    }

    private function getOddCount($n) {
        return intdiv($n, 2) + $n % 2;
    }

    private function getEvenCount($n) {
        return intdiv($n, 2);
    }
}
```
