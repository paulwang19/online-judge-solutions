# LeetCode 166 - Fraction to Recurring Decimal

## 程式碼

```cpp
struct DivisionResult {
    long long dividend;
    long long quotient;
};

class Solution {
private:
    vector<DivisionResult>::const_iterator findDividend(const vector<DivisionResult> &seq, long long dividend) {
        vector<DivisionResult>::const_iterator it;
        for (it = seq.begin(); it != seq.end(); it++) {
            if (it->dividend == dividend) {
                return it;
            }
        }

        return it;
    }

public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) {
            return "0";
        }

        bool negative = (numerator < 0) ^ (denominator < 0);
        long long absNumerator = llabs((long long)numerator);
        long long absDenominator = llabs((long long)denominator);

        string result = negative ? "-" : "";
        result += to_string(absNumerator / absDenominator);
        long long n = absNumerator % absDenominator;
        vector<DivisionResult> divisionSeq;
        vector<DivisionResult>::const_iterator recurringStart;

        while (n != 0) {
            n *= 10;
            long long q = n / absDenominator;
            long long rem = n % absDenominator;
            divisionSeq.push_back({n, q});
            recurringStart = findDividend(divisionSeq, rem * 10);
            if (recurringStart != divisionSeq.end()) {
                break;
            }

            n = rem;
        }

        if (!divisionSeq.empty()) {
            result += ".";
            for (vector<DivisionResult>::const_iterator it = divisionSeq.begin(); it != recurringStart; it++) {
                result += to_string(it->quotient);
            }

            if (recurringStart != divisionSeq.end()) {
                result += "(";
                for (vector<DivisionResult>::const_iterator it = recurringStart; it != divisionSeq.end(); it++) {
                    result += to_string(it->quotient);
                }

                result += ")";
            }
        }

        return result;
    }
};
```
