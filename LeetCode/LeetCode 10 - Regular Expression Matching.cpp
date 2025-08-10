class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.length() == 0) {
            if (s.length() == 0)
                return true;
            return false;
        }

        char pCh = p[0];
        bool zeroOrMore = p.length() >= 2 && p[1] == '*';
        if (!zeroOrMore) {
            if (s.length() == 0) {
                return false;
            }

            if (s[0] == pCh || pCh == '.') {
                return isMatch(s.substr(1), p.substr(1));
            }

            return false;
        }

        int maxPossibleLen = 0;
        if (pCh == '.') {
            maxPossibleLen = s.length();
        } else {
            while (maxPossibleLen < s.length() && s[maxPossibleLen] == pCh) {
                maxPossibleLen++;
            }
        }

        while (maxPossibleLen >= 0) {
            if (isMatch(s.substr(maxPossibleLen), p.substr(2))) {
                return true;
            }

            maxPossibleLen--;
        }

        return false;
    }
};