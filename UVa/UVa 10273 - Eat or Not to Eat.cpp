#include <iostream>
#include <vector>
using namespace std;

#define MAX_COW 1001
#define MAX_CYCLE 11

int cows[MAX_COW][MAX_CYCLE];
int cycle[MAX_COW];
bool killed[MAX_COW];
int numOfCow;

int GCD(int a, int b) {
    if (b) while ((a %= b) && (b %= a));
    return a + b;
}

int LCM(int a, int b) {
    return a * b / GCD(a, b);
}

int ChooseKillNum(int curDay) {
    int minAmount = 251;
    int chooseNum = -1;
    for (int i = 0; i < numOfCow; i++) {
        if (!killed[i] && cows[i][(curDay - 1) % cycle[i]] < minAmount) {
            minAmount = cows[i][(curDay - 1) % cycle[i]];
        }
    }

    int minCowIndex = -1;
    for (int i = 0; i < numOfCow; i++) {
        if (!killed[i] && cows[i][(curDay - 1) % cycle[i]] == minAmount) {
            if (minCowIndex != -1) {  // 出現兩隻以上牛產量同為最少
                return -1;
            }

            minCowIndex = i;
        }
    }

    return minCowIndex;
}

void Test(int nthCase) {
    int maxNoKillDay = 1;
    cin >> numOfCow;
    for (int i = 0; i < numOfCow; i++) {
        cin >> cycle[i];
        killed[i] = false;  // initialize
        maxNoKillDay = LCM(maxNoKillDay, cycle[i]);
        for (int j = 0; j < cycle[i]; j++) {
            cin >> cows[i][j];
        }
    }

    int curDayCount = 0;
    int lastKillDay = 0;
    int curNoKillDay = 0;
    int killCount = 0;
    while (killCount < numOfCow && curNoKillDay < maxNoKillDay) {
        int num = ChooseKillNum(++curDayCount);
        if (num != -1) {
            killed[num] = true;
            lastKillDay = curDayCount;
            curNoKillDay = 0;
            killCount++;
        }
        else {
            curNoKillDay++;
        }
    }

    cout << (numOfCow - killCount) << " " << lastKillDay << endl;
} 

int main() {
    int numOfTest;
    cin >> numOfTest;
    for (int i = 0; i < numOfTest; i++) {
        Test(i + 1);
    }
}