class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {        
        int first = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        if (first == int(nums.size()) )   return vector <int> {-1, -1};
        if (nums[first] != target) return vector <int> {-1, -1};
        
        vector <int> result(2);
        result [0] = first;
        result [1] = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
        return result;
    }
};