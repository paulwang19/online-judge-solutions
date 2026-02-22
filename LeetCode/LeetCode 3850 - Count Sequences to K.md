# LeetCode 3850 - Count Sequences to K

## 程式碼

```cpp
typedef pair<long long, long long> Fraction;

class Solution {
public:
    Fraction simplify(long long num, long long den) {
        if (den < 0) {
            num = -num;
            den = -den;
        }
        
        long long g = gcd(abs(num), abs(den));
        return {num / g, den / g};
    }
    
    int countSequences(vector<int>& nums, long long k) {
        map<Fraction, long long> dp;
        dp[{1, 1}] = 1;

        for (int i = 0; i < nums.size(); i++) {
            map<Fraction, long long> nextDP;
            for (const auto& [frac, count] : dp) {
                long long int num = frac.first;
                long long int den = frac.second;
                nextDP[{num, den}] += count;

                Fraction mulFrac = simplify(num * nums[i], den);
                nextDP[mulFrac] += count;

                Fraction divFrac = simplify(num, den * nums[i]);
                nextDP[divFrac] += count;
            }

            dp = nextDP;
        }
        
        return dp[simplify(k, 1)];
    }
};
```
