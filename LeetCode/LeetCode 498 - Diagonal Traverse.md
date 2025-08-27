# LeetCode 498 - Diagonal Traverse

## 程式碼

```php
class RangeController {
    private $rowSize;
    private $colSize;
    private $startRowIndex;
    private $endRowIndex;
    private $startColIndex;
    private $endColIndex;

    function __construct($rowSize, $colSize) {
        $this->rowSize = $rowSize;
        $this->colSize = $colSize;
        $this->startRowIndex = 0;
        $this->endRowIndex = 0;
        $this->startColIndex = 0;
        $this->endColIndex = 0;
    }

    function get_row_range_array() {
        return range($this->startRowIndex, $this->endRowIndex);
    }

    function get_col_range_array() {
        return range($this->startColIndex, $this->endColIndex);
    }

    function next_range() {
        if ($this->startRowIndex == $this->endRowIndex && $this->endRowIndex == $this->rowSize - 1 &&
            $this->startColIndex == $this->endColIndex && $this->endColIndex == $this->colSize - 1) {
            return false;
        }
        
        if ($this->endRowIndex < $this->rowSize - 1 && $this->endColIndex < $this->colSize - 1) {
            $this->endRowIndex += 1;
            $this->endColIndex += 1;
        }
        elseif ($this->endRowIndex == $this->rowSize - 1) {
            if ($this->endColIndex < $this->colSize - 1) {
                $this->startColIndex += 1;
                $this->endColIndex += 1;
            }
            else {
                $this->startColIndex += 1;
                $this->startRowIndex += 1;
            }
        }
        elseif ($this->endColIndex == $this->colSize - 1) {
            if ($this->endRowIndex < $this->rowSize - 1) {
                $this->startRowIndex += 1;
                $this->endRowIndex += 1;
            }
            else {
                $this->startRowIndex += 1;
                $this->startColIndex += 1;
            }
        }

        return true;
    }
}

class Solution {

    /**
     * @param Integer[][] $mat
     * @return Integer[]
     */
    function findDiagonalOrder($mat) {
        $rangeController = new RangeController(count($mat), count($mat[0]));
        $diagonalOrder = array();
        $hasNext = true;
        $cnt = 0;
        do {
            $rowRange = $rangeController->get_row_range_array();
            $colRange = $rangeController->get_col_range_array();
            $rowRange = $cnt % 2 == 1 ? $rowRange : array_reverse($rowRange);
            $colRange = $cnt % 2 == 0 ? $colRange : array_reverse($colRange);
            for ($i = 0; $i < count($rowRange); $i++) {
                array_push($diagonalOrder, $mat[$rowRange[$i]][$colRange[$i]]);
            }

            $hasNext = $rangeController->next_range();
            $cnt++;
        } while ($hasNext);

        return $diagonalOrder;
    }
}
```
