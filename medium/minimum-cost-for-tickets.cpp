// 983. Minimum Cost For Tickets

// dp(i, reserved)

class Solution {
public:
    vector <int> cst, a, upt = {1, 7, 30};
    int n, ch[1001][400];
    
    int dp(int i, int res)
    {
        if (i == n)
            return 0;
        if (ch[i][res] != -1)   return ch[i][res];
        int ret = 2e9;
        if (a[i] < res)
            ret = min(dp(i + 1, res), ret);
        else{
            for (int k = 0; k < 3; k ++){
                ret = min(ret, cst[k] + dp(i + 1, a[i] + upt[k] ));
            }
        }
        return ch[i][res] = ret;
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        a = days;   n = days.size();    cst = costs;
        memset(ch, -1, sizeof ch);
        return dp(0, 0);    
    }
};
