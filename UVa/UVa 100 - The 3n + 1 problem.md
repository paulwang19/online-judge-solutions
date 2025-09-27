# UVa 100 - The 3n + 1 problem

## 程式碼

```cpp
#include <iostream>
#include <map>
using namespace std;

map<int, int> record;

int GetCycleLength(int n) {
    if (record.find(n) != record.end()) {
        return record[n];
    }

    if (n == 1) {
        record[n] = 1;
        return 1;
    }

    int nextN = n % 2 ? 3 * n + 1 : n / 2;
    if (record.find(nextN) != record.end()) {
        record[n] = record[nextN] + 1;
        return record[n];
    }
    else {
        record[n] = GetCycleLength(nextN) + 1;
        return record[n];
    }
}

int main() {
    int i, j;
    while (cin >> i >> j) {
        int m = i < j ? i : j;
        int M = i > j ? i : j;
        int max = 0;
        for (int k = m; k <= M; k++) {
            int cycleLen = GetCycleLength(k);
            if (cycleLen > max) {
                max = cycleLen;
            }
        }

        cout << i << " " << j << " " << max << endl;
    }
}
```
