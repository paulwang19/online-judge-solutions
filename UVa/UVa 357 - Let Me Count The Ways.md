# UVa 357 - Let Me Count The Ways

## 程式碼

```cpp
#include <iostream>
using namespace std;

#define COIN_WAY 5
#define MAX_M 30000

int main() {
    int coins[COIN_WAY] = {1, 5, 10, 25, 50};
    long long int m[MAX_M + 1] = {0};
    m[0] = 1;
    for (int i = 0; i < COIN_WAY; i++) {
        for (int j = coins[i]; j < MAX_M + 1; j++) {
            m[j] += m[j - coins[i]];
        }
    }

    int n;
    while (cin >> n) {
        if (m[n] == 1) {
            cout << "There is only 1 way to produce " << n << " cents change." << endl;
        }
        else {
            cout << "There are " << m[n] << " ways to produce " << n << " cents change." << endl;
        }
    }
}
```
