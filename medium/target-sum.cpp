// 494. Target Sum

// Intuition
// (i == n) && (curr == target) True Else False
// dp(i, curr) = dp(i + 1, curr + a[i]) + dp(i + 1, curr - a[i]);

class Solution {
public:
    int n, t; vector <int> a;
    map < pair <int, int>, int> ch;
    
    int dp(int i, int cr)
    {
        if (i == n){
            if (cr == t)    return 1;
            else    return 0;
        }
        if (ch.find({i, cr}) != ch.end())    return ch[{i, cr}];
        return ch[{i, cr}] = dp(i + 1, cr + a[i]) + dp(i + 1, cr - a[i]);
    }
    
    int findTargetSumWays(vector<int>& nums, int S) {
        a = nums;   t = S;  n = a.size();   
        return dp(0, 0);
    }
};
