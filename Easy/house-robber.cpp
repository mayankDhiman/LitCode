class Solution {
public:
    
    // Top Down Approach
    vector <int> a, cache; int n;

    int dp(int i){
        if (i >= n) return 0;
        if (cache[i] != -1) return cache[i];
        return cache[i] = max(a[i] + dp(i + 2), dp(i + 1));
    }
    
    int rob(vector<int>& nums) {
        a = nums;   n = nums.size();    vector <int> c(100, -1);    cache = c;
        return dp(0);    
    }
    
    // Bottom Up Approach
    int rob(vector<int>& nums) {
        int n = nums.size(); 
        if (n == 0) return 0;
        else if (n == 1)    return nums[0];

        vector <int> dp(n); dp[0] = nums[0]; dp[1] = nums[1];
        int mx = INT_MIN;
        for (int i = 2; i < n; i ++){
            mx = max(dp[i - 2], mx);
            dp[i] = nums[i] + mx;
        }
        
        return max(dp[n - 1], dp[n - 2]);    
    }
};