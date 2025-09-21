#include <iostream>
#include <algorithm>
using namespace std;

void PrintBinaryRepresentation(bool b[31]) {
    bool isValidDigit = false;
    for (int i = 30; i >= 0; i--) {
        if (!isValidDigit && b[i]) {
            isValidDigit = true;
        }

        if (isValidDigit) {
            cout << b[i];
        }
    }
}

int main() {
    int n;
    while (cin >> n, n) {
        int p = 0;
        bool isOneBit;
        bool b[31];
        for (int i = 0; i < 31; i++) {
            isOneBit = (n & 1 << i) > 0;
            p += isOneBit;
            b[i] = isOneBit;
        }

        cout << "The parity of ";
        PrintBinaryRepresentation(b);
        cout << " is " << p << " (mod 2)." << endl;
    }
}