class Solution {
public:
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
};