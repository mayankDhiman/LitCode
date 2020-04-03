// 628. Maximum Product of Three Numbers

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int ret = INT_MIN, n = nums.size();
        sort(nums.begin(), nums.end());
        ret = max(ret, nums[n - 1] * nums[n - 2] * nums[n - 3]);
        ret = max(ret, nums[0] * nums[1] * nums[n - 1]);
        return ret;
    }
};
