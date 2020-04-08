// 733. Flood Fill

class Solution {
public:
    vector < vector <int> > a;
    int n, m, x, y;
    vector <pair <int, int> > dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    set < pair <int, int> > v;
    
    void dfs(int i, int j) {
        a[i][j] = y;
        v.insert({i, j});
        for (auto d : dir) {
            int i_ = i + d.first, j_ = j + d.second;
            if (v.find({i_, j_}) == v.end()){
                if (i_ < n && i_ > -1 && j_ < m && j_ > -1 && a[i_][j_] == x){
                    dfs(i_, j_);
                }
            }
        }
    }
    

    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image.size() == 0)  return image;
        a = image;  x = a[sr][sc]; y = newColor;
        n = a.size();   m = a[0].size();
        dfs(sr, sc);
        image = a;
        return image;
    }
};
