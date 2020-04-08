// 264. Ugly Number II

class Solution {
public:
    int nthUglyNumber(int n) {
        vector <int> dp(n, -1);
        int p2 = 0, p3 = 0, p5 = 0;
        dp[0] = 1;
        for (int i = 1; i < n; i ++) {
            dp[i] = min({dp[p2] * 2, dp[p3] * 3, dp[p5] * 5}); 
            if (dp[i] == dp[p2] * 2)    p2 += 1;
            if (dp[i] == dp[p3] * 3)    p3 += 1;
            if (dp[i] == dp[p5] * 5)    p5 += 1;
        }
        return dp[n - 1];
    }
};
