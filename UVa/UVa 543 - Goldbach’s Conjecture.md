# UVa 543 - Goldbach’s Conjecture

## 程式碼

```cpp
#include <iostream>
#include <vector>
using namespace std;

#define MAX_N 1000001

vector<int> primeTable;
bool isPrime[MAX_N];

void BuildPrimeTable() {
    isPrime[0] = false;
    isPrime[1] = false;
    isPrime[2] = true;
    for (int i = 3; i < MAX_N; i++) {
        if (i % 2) {
            isPrime[i] = true;
        }
        else {
            isPrime[i] = false;
        }
    }

    for (int b = 3; b * b <= MAX_N; b += 2) {
        for (int i = b * 2; i < MAX_N; i += b) {
            isPrime[i] = false;
        }
    }

    for (int i = 1; i < MAX_N; i++) {
        if (isPrime[i]) {
            primeTable.push_back(i);
        }
    }
}

int main() {
    BuildPrimeTable();
    int n;
    while (cin >> n, n) {
        int a = 0;
        int b = 0;
        for (int i = 1; i < n; i++) {
            if (isPrime[i] && isPrime[n - i]) {
                a = i;
                b = n - i;
                break;
            }
        }

        if (a == 0 && b == 0) {
            cout << "Goldbach's conjecture is wrong." << endl;
        }
        else {
            cout << n << " = " << a << " + " << b << endl;
        }
    }
}
```
