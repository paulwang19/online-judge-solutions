# UVa 382 - Perfection

## 程式碼

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int CountDivisorSum(int n) {
    int divisorSum = 0;
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0) {
            divisorSum += i;
        }
    }

    return divisorSum;
}

int main() {
    cout << "PERFECTION OUTPUT" << endl;
    int inputNum;
    cin >> inputNum;
    while (inputNum != 0) {
        int divisorSum = CountDivisorSum(inputNum);
        if (inputNum == divisorSum) {
            cout << setw(5) << inputNum << "  PERFECT" << endl;
        }
        else if (inputNum > divisorSum) {
            cout << setw(5) << inputNum << "  DEFICIENT" << endl;
        }
        else { // inputNum < divisorSum
            cout << setw(5) << inputNum << "  ABUNDANT" << endl;
        }

        cin >> inputNum;
    }

    cout << "END OF OUTPUT" << endl;
}
```
