class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map <int, int> locations;
        set <int> complements;
        vector <int> ans(2);
        for (int i = 0; i < nums.size(); i ++)
        {
            if (binary_search(complements.begin(), complements.end(), nums[i])){
                ans[0] = min(i, locations[nums[i]]);
                ans[1] = max(i, locations[nums[i]]);
                break;
            }
            complements.insert(target - nums[i]);
            locations[target - nums[i]] = i;
        }
        return ans;
    }
};