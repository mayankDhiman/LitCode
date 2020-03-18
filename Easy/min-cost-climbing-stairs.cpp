class Solution {
public:
    vector <int> a;
    int n, cache[1000];  
    
    int dp(int i){
        if (i >= n){
            return 0;
        }
        
        if (cache[i] != -1) return cache[i];
        
        int res = INT_MAX;
        res = min(a[i] + dp(i + 1), res);
        res = min(a[i] + dp(i + 2), res);
        
        return cache[i] = res;
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        a = cost;   n = cost.size();
        memset(cache, -1, sizeof(cache));
        return min(dp(0), dp(1));
    }
};