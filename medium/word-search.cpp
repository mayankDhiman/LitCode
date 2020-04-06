// Word Search (IMPORTANT)

class Solution {
public:
    vector < vector <char> > a; string t;
    int n, m;
    bool ok;
    
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size(), m = board[0].size();
        a = board;  t = word;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (dfs(i, j, 0))  return 1;
            }
        }
        return 0;
    }
    
    bool dfs(int i, int j, int k) {
        if (k == t.size()){
            return true;
        }
        if ((i > n - 1) || (i < 0) || (j > m - 1) || (j < 0)) {
            return false;
        }
        if (a[i][j] != t[k])    return false;                
        char rep = a[i][j];
        a[i][j] = '#';
        bool ret = dfs(i + 1, j, k + 1) or dfs(i, j + 1, k + 1) 
                    or dfs(i - 1, j, k + 1) or dfs(i, j - 1, k + 1); 
        a[i][j] = rep;
        return ret;
    }
};
