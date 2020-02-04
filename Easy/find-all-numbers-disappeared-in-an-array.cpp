class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector <int> res;   int n = nums.size();
        
        for (int i = 0; i < n; i ++){
            int loc = abs(nums[i]) - 1;
            if (nums[loc] > 0){
                nums[loc] = - nums[loc];
            }
        }
        
        for (int i = 0; i < n; i ++){
            if (nums[i] > 0)    res.emplace_back(i + 1);
        }
        
        return res;
    }
};
