// Minimum Path Sum
// mayankDhiman

class Solution {
public:
    vector < vector <int> > a;
    int n, m, ch[1001][1001];
    
    int dp(int i, int j) {
        if (i == n - 1 && j == m - 1) return a[i][j];
        if (!(i >= 0 && i < n && j >= 0 && j < m))
            return 2e9;
        if (ch[i][j] != -1) return ch[i][j];
        return ch[i][j] = a[i][j] + min(dp(i + 1, j), dp(i, j + 1));
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        a = grid;   n = grid.size();    m = grid[0].size();     memset(ch, -1, sizeof ch);
        return dp(0, 0);
    }
};
