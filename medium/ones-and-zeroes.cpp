class Solution {
public:
    
    // TODO: Optimize
    
    int tot;
    vector <string> a;  vector < vector < vector <int> > > cache;
    
    int dp(int m, int n, int i){    
        if (i == a.size()){
            return 0;
        }
        
        if (cache[m][n][i] != -1)   return cache[m][n][i];
        
        int r1 = 0, r2 = 0;
        if (m >= count(a[i].begin(), a[i].end(), '0') && n >= count(a[i].begin(), a[i].end(), '1')) {
            r1 = 1 + dp(m - count(a[i].begin(), a[i].end(), '0'), n - count(a[i].begin(), a[i].end(), '1'), i + 1);
        }
        r2 = dp(m, n, i + 1);
        
        return cache[m][n][i] = max(r1, r2);
    }
    
        
        
    int findMaxForm(vector<string>& strs, int m, int n) {
        a = strs;
        vector <vector <vector <int> > > _c(101, vector < vector<int>> (101, vector <int> (601, -1)));   cache = _c;
        return dp(m, n, 0);     
    }
};