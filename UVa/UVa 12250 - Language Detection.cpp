#include <iostream>
#include <string>
using namespace std;

int main() {
    int caseCount = 0;
    string str;
    cin >> str;
    while (str.compare("#") != 0) {
        caseCount++;
        if (str.compare("HELLO") == 0) {
            cout << "Case " << caseCount << ": ENGLISH" << endl;
        }
        else if (str.compare("HOLA") == 0) {
            cout << "Case " << caseCount << ": SPANISH" << endl;
        }
        else if (str.compare("HALLO") == 0) {
            cout << "Case " << caseCount << ": GERMAN" << endl;
        }
        else if (str.compare("BONJOUR") == 0) {
            cout << "Case " << caseCount << ": FRENCH" << endl;
        }
        else if (str.compare("CIAO") == 0) {
            cout << "Case " << caseCount << ": ITALIAN" << endl;
        }
        else if (str.compare("ZDRAVSTVUJTE") == 0) {
            cout << "Case " << caseCount << ": RUSSIAN" << endl;
        }
        else {
            cout << "Case " << caseCount << ": UNKNOWN" << endl;
        }

        cin >> str;
    }
}