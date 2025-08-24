#include <iostream>
using namespace std;

#define SUBSET_SIZE 6

void Combination(int *n, int k, int startIndexInN, int *curNumber, int curIndex) {
    if (curIndex == SUBSET_SIZE) {
        for (int i = 0; i < SUBSET_SIZE - 1; i++) {
            cout << curNumber[i] << " ";
        }

        cout << curNumber[SUBSET_SIZE - 1] << endl;
        return;
    }

    for (int i = startIndexInN; i < k; i++) {
        curNumber[curIndex] = n[i];
        Combination(n, k, i + 1, curNumber, curIndex + 1);
    }                        
}

void Combination(int *n, int k) {
    int curNumber[SUBSET_SIZE];
    Combination(n, k, 0, curNumber, 0);
}

int main() {
    int k;
    int n[15];
    cin >> k;
    while (k) {
        for (int i = 0; i < k; i++) {
            cin >> n[i];
        }

        Combination(n, k);
        cin >> k;
        if (k) {
            cout << endl;
        }
    }
}