// 200. Number of Islands

class Solution {
public:
    vector < vector <char> > a;
    int n, m;
    vector <pair <int, int> > dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    set < pair <int, int> > v;
    
    void dfs(int i, int j) {
        v.insert({i, j});
        for (auto d : dir) {
            int i_ = i + d.first, j_ = j + d.second;
            if (v.find({i_, j_}) == v.end()){
                if (i_ < n && i_ > -1 && j_ < m && j_ > -1 && a[i_][j_] == '1'){
                    dfs(i_, j_);
                }
            }
        }
    }
    
    
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0){
            return 0;
        }
        a = grid;   n = grid.size();    m = grid[0].size();
        int ret = 0;        
        for (int i = 0; i < n; i ++){
            for (int j = 0; j < m; j ++){
                if (a[i][j] == '1'){
                    if (v.find({i, j}) == v.end()){
                        ret += 1;
                        dfs(i, j);
                    }
                }
            }
        }
        
        return ret;
    }
};
