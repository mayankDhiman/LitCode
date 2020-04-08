// 695. Max Area of Island

class Solution {
public:
    vector < vector <int> > a;
    int n, m, cn;
    vector <pair <int, int> > dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    set < pair <int, int> > v;
    
    void dfs(int i, int j) {
        v.insert({i, j});
        cn += 1;
        for (auto d : dir) {
            int i_ = i + d.first, j_ = j + d.second;
            if (v.find({i_, j_}) == v.end()){
                if (i_ < n && i_ > -1 && j_ < m && j_ > -1 && a[i_][j_] == 1){
                    dfs(i_, j_);
                }
            }
        }
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        a = grid;   n = a.size();   
        if (n == 0) return 0;
        m = a[0].size();    v.clear();
        int ret = 0;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (a[i][j] == 1){
                    if (v.find({i, j}) == v.end()){
                        cn = 0;
                        dfs(i, j);
                        cout << cn << "\n";
                        ret = max(cn, ret);                        
                    }
                }
            }
        }
        return ret;
    }
};
