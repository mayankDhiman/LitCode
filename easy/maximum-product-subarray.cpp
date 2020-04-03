// 152. Maximum Product Subarray

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ret = nums[0], n = nums.size();
        for (int i = 1, mx = ret, mn = ret; i < n; i ++){
            if (nums[i] < 0)   swap(mx, mn);
            mx = max(nums[i], mx * nums[i]);
            mn = min(nums[i], mn * nums[i]);
            ret = max(mx, ret);
        }
        return ret;
    }
};