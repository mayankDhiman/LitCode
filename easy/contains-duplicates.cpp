// 217. Contains Duplicate

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map <int, int> mp;
        for (auto n : nums) {
            if (mp.find(n) == mp.end()) mp[n] += 1;
            else    return 1;
        }
        return 0;
    }       
};
