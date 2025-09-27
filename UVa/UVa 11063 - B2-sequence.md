# UVa 11063 - B2-sequence

## 程式碼

```cpp
#include <iostream>
#include <unordered_set>
using namespace std;

bool IsB2Sequence(int *b, int n) {
    unordered_set<int> pairSumSet;
    for (int i = 0; i < n; i++) {
        if (b[i] <= 0) {
            return false;
        }

        for (int j = i; j < n; j++) {
            int pairSum = b[i] + b[j];
            if (b[i] > b[j] || pairSumSet.count(pairSum) > 0) {
                return false;
            }

            pairSumSet.insert(pairSum);
        }
    }

    return true;
}

int main() {
    int n;
    int b[100];
    int caseCnt = 1;
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        if (IsB2Sequence(b, n)) {
            cout << "Case #" << caseCnt++ << ": It is a B2-Sequence." << endl;
        }
        else {
            cout << "Case #" << caseCnt++ << ": It is not a B2-Sequence." << endl;
        }

        cout << endl;
    }
}
```
