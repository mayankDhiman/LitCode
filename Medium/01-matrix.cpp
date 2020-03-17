class Solution {
public:
    #define ll long long
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector < vector <int> >   dp(n, vector <int> (m, INT_MAX));
       
        for (ll i = 0; i < n; i ++){
            for (ll j = 0; j < m; j ++){
                if (!matrix[i][j]){
                    dp[i][j] = 0;
                }
            }
        }
                
        for (ll i = 0; i < n; i ++){
            for (ll j = 0; j < m; j ++){
                if (i > 0){
                    if (dp[i - 1][j] != INT_MAX){
                        dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j]);
                    }
                }
                if (j > 0){
                    if (dp[i][j - 1] != INT_MAX){
                        dp[i][j] = min(dp[i][j], 1 + dp[i][j - 1]);
                    }                    
                }                
            }
        }
        
        for (ll i = n - 1; i >= 0; i --){                
            for (ll j = m - 1; j >= 0; j --){
                if (i < n - 1){
                    if (dp[i + 1][j] != INT_MAX){
                        dp[i][j] = min(dp[i + 1][j] + 1, dp[i][j]);
                    }
                }
                
                if (j < m - 1){
                    if (dp[i][j + 1] != INT_MAX){
                        dp[i][j] = min(dp[i][j], 1 + dp[i][j + 1]);
                    }                    
                }                        
            }
        }
        
        return dp;
 
        }
    };
