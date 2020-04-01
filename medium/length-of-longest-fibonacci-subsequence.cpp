// 873. Length of Longest Fibonacci Subsequence

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& a) {
        int n = a.size();
        vector < vector <int> > dp(n, vector <int> (n, 2));
        unordered_map <int, int> av;
        for (int i = 0; i < n; i ++){
            for (int j = i + 1; j < n; j ++){
                int x = a[j] - a[i];
                if (av.find(x) != av.end()){
                    dp[i][j] = dp[av[x]][i] + 1;
                }
            }
            av[a[i]] = i;
        }        
        int ret = 0;
        for (int i = 0; i < n; i ++){
            for (int j = i + 1; j < n; j ++){
                ret = max(ret, dp[i][j]);
            }
        }
        return (ret == 2) ? 0 : ret;
    }
};