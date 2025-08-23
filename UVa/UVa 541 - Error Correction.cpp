#include <iostream>
using namespace std;

int main() {
    int n, b;
    int rowSum[100], colSum[100];
    while (cin >> n && n != 0) {
        for (int i = 0; i < n; i++) {
            rowSum[i] = 0;
            colSum[i] = 0;
        }

        for (int i = 0 ; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> b;
                rowSum[i] += b;
                colSum[j] += b;
            }
        }

        int oddRowIndex = -1;
        int oddColIndex = -1;
        bool isCorrupt = false;
        for (int i = 0; i < n; i++) {
            if (rowSum[i] % 2 == 1) {
                if (oddRowIndex == -1) {
                    oddRowIndex = i;
                }
                else {
                    isCorrupt = true;
                    break;
                }
            }

            if (colSum[i] % 2 == 1) {
                if (oddColIndex == -1) {
                    oddColIndex = i;
                }
                else {
                    isCorrupt = true;
                    break;
                }
            }
        }

        if (oddRowIndex == -1 && oddColIndex == -1) {
            cout << "OK" << endl;
        }
        else if (oddRowIndex != -1 && oddColIndex != -1 && !isCorrupt) {
            cout << "Change bit (" << oddRowIndex + 1 << "," << oddColIndex + 1 << ")" << endl;
        }
        else {
            cout << "Corrupt" << endl;
        }
    }
}