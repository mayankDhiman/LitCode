
class Solution {
public:
    set <vector <int> > s;    int n;  vector <int> a;
    
    void dp(int i, vector <int> cr){        
        if (i == n){
            sort(cr.begin(), cr.end());
            s.insert(cr);
            return;
        }
        dp(i + 1, cr);
        vector <int> cr1 = cr;  cr1.emplace_back(a[i]);
        dp(i + 1, cr1);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector <int> cr;    a = nums;       n = a.size();       s.clear();
        dp(0, cr);      
        vector <vector <int> > res(s.begin(), s.end());
        return res;
    }
};