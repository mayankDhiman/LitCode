class Solution {
public:
    // Top Down Approach
    vector < vector <int> > grid, cache;   int n, m;
    
    int dp(int i, int j) {
        if (i >= n || j >= m || grid[i][j] == 1)    return 0;
        if (i == n - 1 && j == m - 1)   return 1;
        
        if (cache[i][j] != -1)  return cache[i][j];
        
        return cache[i][j] = dp(i + 1, j) + dp(i, j + 1);
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        grid = obstacleGrid;
        n = grid.size();    m = grid[0].size();     vector < vector <int> > _cache(100, vector <int> (100, -1));    cache = _cache;
        return dp(0, 0);
    }
    
    
    
    // Bottom Up Approach
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        vector < vector <long long> > dp(n, vector <long long> (m, 0));
        
        if (!obstacleGrid[0][0]) dp[0][0] = 1;                
        for (int i = 0; i < n; i ++)
        { 
            for (int j = 0; j < m; j ++)
            {   
                if (!i && !j)   continue;
                
                if (obstacleGrid[i][j] == 0){
                    if (i == 0)
                        dp[i][j] = dp[i][j - 1];
                    else if (j == 0)
                        dp[i][j] = dp[i - 1][j];
                    else
                        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[n - 1][m - 1];
    }
};