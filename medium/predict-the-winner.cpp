class Solution {
public:
    vector <int> a; int n;

    int dp(int i, int j, int turn){
        if (i > j)  return 0;
        
        /* Easy min-max */
        if (turn == 1){
            int r1 = a[i] + dp(i + 1, j, -turn);
            int r2 = a[j] + dp(i, j - 1, -turn);
            return max(r1, r2);
        }
        else{
            int r1 = -a[i] + dp(i + 1, j, -turn);
            int r2 = -a[j] + dp(i, j - 1, -turn);
            return min(r1, r2);
        }
        
        /* Hard min-max */
        int r1 = turn*a[i] + dp(i + 1, j, -turn);
        int r2 = turn*a[j] + dp(i, j - 1, -turn);
        
        return turn * max(turn * r1, turn * r2);
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();    a = nums;
        return (dp(0, n - 1, 1) >= 0);
    }
};
