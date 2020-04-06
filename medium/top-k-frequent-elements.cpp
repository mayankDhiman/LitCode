// 347. Top K Frequent Elements

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       unordered_map <int, int> cn;
        for (int i = 0; i < nums.size(); i ++) {
            cn[nums[i]] += 1;
        }
        multimap <int, int, greater <int> > icn;
        for (auto x : cn)
            icn.insert({x.second, x.first});
        vector <int> ret;
        for (auto x : icn) {
            ret.emplace_back(x.second);
            if (ret.size() == k)    break;
        }
        return ret;
    }
};
