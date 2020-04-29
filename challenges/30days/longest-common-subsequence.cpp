// Longest Common Subsequence

class Solution {
public:
    int dp[1001][1001], n, m; string a, b;
    
    int bt(int i, int j){
        if (i == n or j == m) return 0;
        if (dp[i][j] != -1) return dp[i][j];  
        if (a[i] == b[j]) return dp[i][j] = 1 + bt(i + 1, j + 1);
        else return dp[i][j] = max(bt(i, j + 1), bt(i + 1, j));
    }
    
    
    int longestCommonSubsequence(string text1, string text2) {
        a = text1; b = text2; n = a.size(); m = b.size(); memset(dp, -1, sizeof dp);
        return bt(0, 0);
    }
};
