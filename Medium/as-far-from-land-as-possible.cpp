// 1162. As Far from Land as Possible

class Solution {
public:
    int maxDistance(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        vector < vector <int> > dp(n, vector <int> (m, 1e9));
        for (int i = 0; i < n; i ++){
                for (int j = 0; j < n; j ++){
                    if (a[i][j] == 1)   dp[i][j] = 0;
                }
        }
        for (int i = 0; i < n; i ++){
            for (int j = 0; j < m; j ++){
                if (i > 0)
                    dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
                if (j > 0)
                    dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
            }
        }
        for (int i = n - 1; i >= 0; i --){
            for (int j = m - 1; j >= 0; j --){
                if (i < n - 1)
                    dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1);
                if (j < m - 1)
                    dp[i][j] = min(dp[i][j], dp[i][j + 1] + 1);
            }
        }
        int c1 = 0 , c2 = 0;
        for (auto i : dp){
            for (auto j : i){
                if (j) c1 += 1;
                else c2 += 1;
            }
        }
        if  (!(c1 && c2)){
            return -1;
        }
        int ret = 0;
        for (auto i : dp){
            for (auto j : i){
                ret = max(j, ret);
            }
        }
        return ret;
    }
};