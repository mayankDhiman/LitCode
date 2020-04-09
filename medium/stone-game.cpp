// 877. Stone Game

class Solution {
public:
    vector <int> a; int n;
    int ch[501][501][2];
    
    int dp(int i, int j, int turn) {
        if (i == j) {
            if (turn)   return a[i];
            else    return -a[i];
        }
        if (i > j)  return 0;
        if (ch[i][j][turn] != -1)   return ch[i][j][turn];
        if (turn) {
            int r1 = a[i] + dp(i + 1, j, !turn);
            int r2 = a[j] + dp(j - 1, i, !turn);
            return ch[i][j][turn] = max(r1, r2);
        } 
        else {
            int r1 = - a[i] + dp(i + 1, j, !turn);
            int r2 = - a[j] + dp(j - 1, i, !turn);
            return ch[i][j][turn] = min(r1, r2);
        }
    }
    
    bool stoneGame(vector<int>& piles) {
        a = piles;  n = a.size();   memset(ch, -1, sizeof ch);
        return (dp(0, n - 1, 1) > 0);    
    }
};
