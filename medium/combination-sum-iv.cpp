// 377. Combination Sum IV (NICE)

class Solution {
public:
    vector <int> a; int n; int s;
    int ch[100000];
    
    int dp(int s)
    {
        if (s == 0) return 1;
        if (s < 0)  return 0;
        
        if (ch[s] != -1)    return ch[s];
        
        int ret = 0;
        for (int i = 0; i < n; i ++){
            ret += dp(s - a[i]);
        }
        return ch[s] = ret;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        memset(ch, -1, sizeof ch);
        a = nums; n = nums.size(); s = target;            
        return dp(s);
    }
};