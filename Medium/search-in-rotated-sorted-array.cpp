class Solution {
public:
    int pivot_find(vector <int> nums) {
        int lo = 0, hi = nums.size() - 1;
        while (lo < hi) {
            int md = (lo + hi)/2;
            if (nums[md] >= nums[0])
                lo = md + 1;
            else 
                hi = md;
        }
        return lo;
    }
    
    int result_find(vector <int> nums, int target, int r) {
        int _r1 = lower_bound(nums.begin(), nums.begin() + r, target) - nums.begin();
        int _r2 = lower_bound(nums.begin() + r, nums.end(), target) - nums.begin();
        
        if (_r1 == r || (nums[_r1] != target)){
            if (_r2 == nums.size() || (nums[_r2] != target))
                    return -1;
            else
                    return _r2;
        }  
        else{
            return _r1;
        }        
    }
    
    int search(vector<int>& nums, int target) {
        int pv = pivot_find(nums);
        return result_find(nums, target, pv);
    }
};