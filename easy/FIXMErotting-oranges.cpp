// 994. Rotting Oranges

class Solution {
public:
    vector < vector <int> > a;
    int n, m;
    vector <pair <int, int> > dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    set < pair <int, int> > v;
    vector < vector <int> > d;
    
    void bfs (int i, int j) {
        queue < pair <int, int> > q;
        v.insert({i, j});
        q.push({i, j});
        while (!q.empty()){
            pair <int, int> f = q.front();  int x = f.first, y = f.second;
            q.pop();
            v.insert({x, y});
            a[x][y] = 2;
            for (auto _d : dir) {
                int i_ = x + _d.first, j_ = y + _d.second;
                if (v.find({i_, j_}) == v.end()){
                    if (i_ < n && i_ > -1 && j_ < m && j_ > -1 && a[i_][j_] == 1){
                        q.push({i_, j_});
                        d[i_][j_] = d[x][y] + 1;
                    }
                }
            }
        }
    }
                        
                    
    int orangesRotting(vector<vector<int>>& grid) {
        a = grid; n = grid.size(); m = grid[0].size(); v.clear();
        d.resize(n, vector <int> (m, 0));
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (a[i][j] == 2){
                    if (v.find({i, j}) == v.end()){
                        bfs(i, j);
                    }
                }
            }
        }
        bool ok = 1;    int ret = 0;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++){
                if (a[i][j] == 1)   ok = 0;
                cout << d[i][j] << "\n";
                ret = max(ret, d[i][j]);
            }
        }        
        if (ok) return ret;
        else return -1;
    }
};
