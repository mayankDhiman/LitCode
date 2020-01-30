class Solution {
public:
    int _m, _n; vector <vector<int> > cache;
    
    int dp(int i, int j){      
        if (i >= _m || j >= _n) return 0;
        if (i == _m - 1 && j == _n - 1) return 1;
        
        if (cache[i][j] != -1)  return cache[i][j];
        
        return cache[i][j] = dp(i + 1, j) + dp(i, j + 1);
    }
    
    int uniquePaths(int m, int n) {
        _m = m; _n = n; vector < vector <int> > _cache(100, vector <int> (100, -1));    cache = _cache;
        return dp(0, 0);    
    }
};