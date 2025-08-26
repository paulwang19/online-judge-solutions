# LeetCode 3000 - Maximum Area of Longest Diagonal Rectangle

## 程式碼

```php
class Solution {

    /**
     * @param Integer[][] $dimensions
     * @return Integer
     */
    function areaOfMaxDiagonal($dimensions) {
        $maxDiagonal = 0;
        $maxArea = 0;
        foreach ($dimensions as $dimension) {
            $diagonal = pow($dimension[0], 2) + pow($dimension[1], 2);
            $area = $dimension[0] * $dimension[1];
            if ($diagonal > $maxDiagonal) {
                $maxDiagonal = $diagonal;
                $maxArea = $area;
            }
            elseif ($diagonal === $maxDiagonal && $area > $maxArea) {
                $maxArea = $area;
            }
        }

        return $maxArea;
    }
}
```
