class Solution {
public:
    vector <int> cache;
    
    int dp(int n) {
        if (n == 0) return 0;
        if (n < 0)  return INT_MAX;

        if (cache[n] != -1) return cache[n];
         
        int result = INT_MAX;
        for (int i = 1; i * i <= n; i ++){
            result = min(1 + dp(n - i*i), result);
        }

        return cache[n] = result;
    }
    
    int numSquares(int n) {
        cache.resize(100000, -1);
        return dp(n);
    }
};
