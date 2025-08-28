# LeetCode 3446 - Sort Matrix by Diagonals

## 程式碼

```php
class Solution {

    /**
     * @param Integer[][] $grid
     * @return Integer[][]
     */
    function sortMatrix($grid) {
        for ($i = count($grid) - 1; $i >= 0; $i--) {
            $arr = $this->collectDiagonalArray($grid, $i, 0);
            $this->quickSort($arr, 0, count($arr), false);
            $this->assignDiagonal($grid, $i, 0, $arr);
        }

        for ($i = 1; $i < count($grid); $i++) {
            $arr = $this->collectDiagonalArray($grid, 0, $i);
            $this->quickSort($arr, 0, count($arr));
            print_r($arr);
            $this->assignDiagonal($grid, 0, $i, $arr);
        }

        return $grid;
    }

    private function collectDiagonalArray($grid, $startX, $startY) {
        $i = $startX;
        $j = $startY;
        $arr = array();
        while ($i < count($grid) && $j < count($grid[0])) {
            array_push($arr, $grid[$i][$j]);
            $i++;
            $j++;
        }

        return $arr;
    }

    private function assignDiagonal(&$grid, $startX, $startY, $arr) {
        $i = $startX;
        $j = $startY;
        while ($i < count($grid) && $j < count($grid[0])) {
            $grid[$i][$j] = current($arr);
            $i++;
            $j++;
            next($arr);
        }
    }

    private function quickSort(&$arr, $start, $end, $asc = true) {
        if ($end - $start <= 1) {
            return;
        }

        $pivot = $start;
        for ($i = $start + 1; $i < $end; $i++) {
            $change = $asc && $arr[$i] < $arr[$pivot] || !$asc && $arr[$i] > $arr[$pivot];
            if ($change) {
                $this->swap($arr[$pivot], $arr[$i]);
                $pivot++;
                $this->swap($arr[$i], $arr[$pivot]);
            }
        }

        $this->quickSort($arr, $start, $pivot, $asc);
        $this->quickSort($arr, $pivot + 1, $end, $asc);
    }

    private function swap(&$a, &$b) {
        $temp = $a;
        $a = $b;
        $b = $temp;
    }
}
```
