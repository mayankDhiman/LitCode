// Product of array except self

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector <int> ret(nums.begin(), nums.end());    long long ml = 1, n = nums.size();
        if (find(nums.begin(), nums.end(), 0) == nums.end()){
            for (long long i = 0; i < n; i ++)    
                ml *= nums[i];
            for (auto &i : ret){
                i = (ml / i);
            }            
        }
        else{
            if (count(nums.begin(), nums.end(), 0) > 1){
                for (auto &i : ret) i = 0;
                return ret;
            }
            for (long long i = 0; i < n; i ++)
                if (nums[i])
                    ml *= nums[i];
            for (auto &i : ret){
                if (!i) i = ml;
                else    i = 0;
            }
        }
        return ret;
    }
};
