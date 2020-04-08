130. Surrounded Regions

class Solution {
public:
    vector < vector <char> > a, a_;
    int n, m;
    vector <pair <int, int> > dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    set < pair <int, int> > v;
    bool ok;
    
    
    void dfs(int i, int j) {
        v.insert({i, j});
        a_[i][j] = 'X';
        for (auto d : dir) {
            int i_ = i + d.first, j_ = j + d.second;
            if (v.find({i_, j_}) == v.end()){
                if (!(i_ < n && i_ > -1 && j_ < m && j_ > -1)){
                    ok = 0;
                }
                else{
                    if (a[i_][j_] == 'O'){
                        dfs(i_, j_);
                    }                    
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        a_ = a = board;   
        if (board.size() == 0) return;
        n = a.size(), m = a[0].size();
        
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (a[i][j] == 'O'){
                    if (v.find({i, j}) == v.end()){
                        ok = 1;   
                        dfs(i, j);
                        if (ok){
                            a = a_;
                        }
                        else{
                            a_ = a;
                        }
                    }
                }
            }
        }
        board = a;
    }
};


