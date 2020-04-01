class Solution {
public:
    vector <vector <int> > _triangle, cache;
    
    int dp(int i, int j){
        if (i == _triangle.size() - 1){
            return _triangle[i][j];
        }
        
        if (cache[i][j] != -1)  return cache[i][j];
        
        return cache[i][j] = min(_triangle[i][j] + dp(i + 1, j), _triangle[i][j] + dp(i + 1, j + 1));
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        _triangle = triangle;   cache.resize(5000, vector <int> (5000, -1));
        return dp(0, 0);
    }
};
