// 46. Permutations
// Backtrack Problem

class Solution {
public:
    set < vector <int> > ret1;
    
    void bt(vector <int> a, set<int> b){
        if (b.empty()){
            ret1.emplace(a);
            return;
        }
        for (auto x : b){
            vector <int> a_ = a; set <int> b_= b;
            a_.emplace_back(x), b_.erase(x);
            bt(a_, b_);
        }
        return;
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector <int> a; set <int> b(nums.begin(), nums.end());
        bt(a, b);
        vector < vector <int> > ret(ret1.begin(), ret1.end());
        return ret;
    }
};
