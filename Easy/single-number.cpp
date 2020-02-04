class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // Maths
        set <int> t;    int sm = 0;
        for (int i = 0; i < nums.size(); i ++){
            t.insert(nums[i]);
            sm += nums[i];
        }
        return (accumulate(t.begin(), t.end(), 0)*2 - sm);

        // Bit Manipulation
        int res = 0;
        for (auto i : nums){
            res ^= i;
        }
        return res;
    }
};
