// 219. Contains Duplicate II

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map <int, int> pos;
        for (int i = 0; i < nums.size(); i ++) {
            if (pos.find(nums[i]) == pos.end())
                pos[nums[i]] = i;
            else {
                if (i - pos[nums[i]] <= k)
                    return 1;
                else
                    pos[nums[i]] = i;
            }
        }
        return 0;
    }
};
