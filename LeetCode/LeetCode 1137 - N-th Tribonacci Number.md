# LeetCode 1137 - N-th Tribonacci Number

## 程式碼

```c
int tribonacci(int n) {
    int dp[40] = {0};
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
    }

    return dp[n];
}
```
