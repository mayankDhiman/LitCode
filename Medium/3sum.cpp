// TLE in two cases

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set < vector <int> > result;
        for (int i = 0; i < nums.size(); i ++)
        {
            int two_sum = -nums[i];
            set <int> complements; 
            for (int j = 0; j < nums.size(); j ++)
            {
                if (j != i)
                {
                    if (binary_search(complements.begin(), complements.end(), nums[j]))
                    {
                        vector <int> set{-two_sum, nums[j], two_sums - nums[j]};
                        sort(set.begin(), set.end());
                        result.insert(set);
                    }
                    else
                    {
                        complements.insert(two_sum - nums[j]);
                    }
                }
            }
        }
        vector <vector <int>> _result(result.begin(), result.end());
        return _result;
    }
};