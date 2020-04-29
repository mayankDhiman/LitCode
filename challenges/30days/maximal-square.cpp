// Maximal Square

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(); 
        if (n == 0) return 0;
        int m = matrix[0].size(), result = 0;
        vector < vector <int> > dp(n, vector <int> (m));
        for (int i = 0; i < n; i ++){
            for (int j = 0; j < m; j ++){
                if (matrix[i][j] == '1'){
                    dp[i][j] = 1;
                    if (i > 0 && j > 0){
                        dp[i][j] += min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]});
                    }
                }
                result = max(result, dp[i][j]);
            }
        }
        return result * result;
    }
};
