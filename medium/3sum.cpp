class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set < vector <int> > result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i ++)
        {
            int target = - nums[i];
            int l = i + 1, r = nums.size() - 1;          
            while (l < r)
            {
                vector <int> sett(3);
                if (nums[l] + nums[r] < target) l += 1;
                else if (nums[l] + nums[r] > target) r -= 1;
                else 
                {

                    sett[0] = nums[i];
                    sett[1] = nums[l];
                    sett[2] = nums[r];
                    sort(sett.begin(), sett.end());
                    result.insert(sett);
                    l += 1;
                    r -= 1;
                }                
                while(l < r && nums[l] == sett[1])  l += 1;
                while(l < r && nums[r] == sett[2])  r -= 1;
            }
            while(i + 1 < nums.size() && nums[i + 1] == nums[i])    i += 1;        
        }
        vector <vector <int>> _result(result.begin(), result.end());
        return _result;
    }
};