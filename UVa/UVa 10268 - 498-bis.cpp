#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main() {
    int value;
    string lineStr;
    vector<int> coefficients;
    while (cin >> value) {
        getline(cin, lineStr);  // clear end line
        coefficients.clear();

        getline(cin, lineStr);
        stringstream ss(lineStr);
        int coef;
        while (ss >> coef) {
            coefficients.push_back(coef);
        }

        int sum = 0;
        int term = 1;
        int numOfCoef = coefficients.size();
        for (int i = numOfCoef - 2, term = 1; i >= 0; i--, term *= value) {
            sum += coefficients.at(i) * (numOfCoef - i - 1) * term;
        }

        cout << sum << endl;
    }
}