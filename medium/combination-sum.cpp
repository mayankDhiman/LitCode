// 39. Combination Sum

class Solution {
public:
    int n, s;    vector <int> a;
    vector < vector <int> > ret;
    
    
    void dfs(int i, vector <int> cr, int cs) {
        if (cs < 0) return;    
        if (cs == 0){
            ret.push_back(cr);
            return;
        }
        for (int j = i; j < n; j ++) {
            vector <int> cr_ = cr;  cr_.emplace_back(a[j]);
            dfs(j, cr_, cs - a[j]);
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        a = candidates; n = candidates.size();  s = target; ret.clear();
        vector <int> cr;
        dfs(0, cr, s);        
        return ret;
    }
};
