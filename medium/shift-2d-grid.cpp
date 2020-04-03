// 1260. Shift 2D Grid

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector < vector <int> > ret(n, vector <int> (m, 0));
        vector <int> ch(m);
        for (auto &i : ch)  i = k / m;
        for (int i = m - 1; i >= m - (k%m); i --)   ch[i] += 1;
        for (int i = 0; i < n; i ++){
            for (int j = 0; j < m; j ++){
                int jj = (j + k)%m;
                int ii = (i + ch[j])%n;        
                ret[ii][jj] = grid[i][j];
            }
        }
        return ret;
    }
};

// change in column number: j' = (j + k)%m
// change in row number:
// 1. 0 0 0 1
// 2  0 0 1 1
// 3  0 1 1 1
// 4  1 1 1 1
// 5  1 1 1 2
// 6  1 1 2 2
// 7  1 2 2 2
// 8  2 2 2 2

