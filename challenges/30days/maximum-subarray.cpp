// Maximum Subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(); vector <int> dp(n);
        for (int i = 0; i < n; i ++)   dp[i] = nums[i];
        int ret = dp[0];
        for (int i = 1; i < n; i ++) {
            dp[i] = max(dp[i], dp[i] + dp[i - 1]);
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};
