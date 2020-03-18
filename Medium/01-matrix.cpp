class Solution {
public:
    /* DP Solution */
//         int n = matrix.size(), m = matrix[0].size();
//         vector < vector <int> >   dp(n, vector <int> (m, INT_MAX));
       
//         for (ll i = 0; i < n; i ++){
//             for (ll j = 0; j < m; j ++){
//                 if (!matrix[i][j]){
//                     dp[i][j] = 0;
//                 }
//             }
//         }
                
//         for (ll i = 0; i < n; i ++){
//             for (ll j = 0; j < m; j ++){
//                 if (i > 0){
//                     if (dp[i - 1][j] != INT_MAX){
//                         dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j]);
//                     }
//                 }
//                 if (j > 0){
//                     if (dp[i][j - 1] != INT_MAX){
//                         dp[i][j] = min(dp[i][j], 1 + dp[i][j - 1]);
//                     }                    
//                 }                
//             }
//         }
        
//         for (ll i = n - 1; i >= 0; i --){                
//             for (ll j = m - 1; j >= 0; j --){
//                 if (i < n - 1){
//                     if (dp[i + 1][j] != INT_MAX){
//                         dp[i][j] = min(dp[i + 1][j] + 1, dp[i][j]);
//                     }
//                 }
                
//                 if (j < m - 1){
//                     if (dp[i][j + 1] != INT_MAX){
//                         dp[i][j] = min(dp[i][j], 1 + dp[i][j + 1]);
//                     }                    
//                 }                        
//             }
//         }
        
//         return dp;
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
            int n = matrix.size(), m = matrix[0].size();  
            vector < vector <long long> > dist(n, vector <long long> (m, INT_MAX)) ;
            
        
            queue < pair <int, int> > q;
            for(int i = 0; i < n; i ++){
                for (int j = 0; j < m; j ++){
                    if (matrix[i][j] == 0){
                        q.push({i, j});
                        dist[i][j] = 0;
                    }
                }
            }

        
            vector <pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};    
            while(!q.empty()){
                pair <int, int> x = q.front();  q.pop();
                for (int i = 0; i < 4; i ++){
                    int r1 = x.first + dir[i].first;
                    int c1 = x.second + dir[i].second;
                    if (r1 < n && r1 >= 0 && c1 >= 0 && c1 < m){
                        if (dist[r1][c1] > dist[x.first][x.second] + 1){
                            dist[r1][c1] = dist[x.first][x.second] + 1;
                            q.push({r1, c1});
                        }
                    }
                }
            }
        
        
            vector < vector <int> > res(n, vector <int> (m) );
            for (int i = 0; i < n; i ++){
                for (int j = 0; j < m; j ++){
                    res[i][j] = dist[i][j];
                }
            }
            return res;
        }
    };
