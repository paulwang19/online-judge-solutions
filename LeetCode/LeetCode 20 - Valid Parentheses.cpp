class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (int i = 0; i < s.length(); i++) {
            char ch = s.at(i);
            if (ch == '(' || ch == '[' || ch == '{') {
                stk.push(ch);
            } else {
                if (stk.empty()) {
                    return false;
                }

                char topCh = stk.top();
                stk.pop();
                if (ch == ')' && topCh != '(' || ch == ']' && topCh != '[' ||
                    ch == '}' && topCh != '{') {
                    return false;
                }
            }
        }

        return stk.empty();
    }
};