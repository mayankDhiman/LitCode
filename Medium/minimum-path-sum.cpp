class Solution {
public:

    int n, m;   vector <vector <int> > a, cache;

    //  Top Down Solution
    int dp(int i, int j) {
        if (i == n - 1 && j == m - 1)   return a[i][j]; 
        if (i >= n || j >= m)     return INT_MAX;

        if (cache[i][j] != -1)  return cache[i][j];
        
        return cache[i][j] = a[i][j] + min(dp (i + 1, j), dp(i, j + 1));

    }
    
    int minPathSum(vector<vector<int>>& grid) {
        n = grid.size();    m = grid[0].size();     a = grid;
        vector < vector <int> > _c(1000, vector <int> (1000, -1));    cache = _c;
        return dp(0, 0);    
    }
    

    //  Bottom Up Solution    
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector < vector <int> > cache(n, vector <int> (m, -1));
        
        
        cache[0][0] = grid[0][0];    
        for (int i = 1; i < n; i ++)    cache[i][0] = cache[i - 1][0] + grid[i][0];  
        for (int i = 1; i < m; i ++)    cache[0][i] = cache[0][i - 1] + grid[0][i];  
        
        for (int i = 1; i < n; i ++){
            for (int j = 1; j < m; j ++){
                cache[i][j] = grid[i][j] + min(cache[i][j - 1], cache[i - 1][j]);
            }
        }
        
        return cache[n - 1][m - 1];
    }
};