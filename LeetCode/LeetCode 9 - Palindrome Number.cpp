class Solution {
public:
    bool isPalindrome(int x) {
        string numStr = to_string(x);
        int i = 0;
        int j = numStr.length() - 1;
        while (i < j) {
            if (numStr[i] != numStr[j]) {
                return false;
            }

            i++;
            j--;
        }

        return true;
    }
};