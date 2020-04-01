class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Bayer-Moore Voting Algorithm
        int curr_mj = nums[0], n = nums.size(), count = 0;
        for (int i = 0; i < n; i ++){
            
            if (!count){
                curr_mj = nums[i];
            }
            
            if (nums[i] == curr_mj) count += 1;
            else    count -= 1;
        }
        
        return curr_mj;
    }
};