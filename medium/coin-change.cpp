// 322. Coin Change

// dp(s < 0) = -2e9
// dp(0) = 1
// dp(target) = 1 + min(dp(target - a[i]))  0 <= i < n

class Solution {
public:
    int n, t;  vector <int> a;
    int ch[int(1e5 + 1)];
    
    int dp(int t){
        if (t < 0)  return +2e9;
        if (t == 0) return 0;
        if (ch[t] != -1)    return ch[t];
        int ret = 2e9;
        for (int i = 0; i < n; i ++)
            ret = min(ret, 1 + dp(t - a[i]));
        return ch[t] = ret;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        a = coins;  n = coins.size();   t = amount;
        memset(ch, -1, sizeof ch);
        return (dp(amount) == 2e9) ? -1 : dp(amount);
    }
};