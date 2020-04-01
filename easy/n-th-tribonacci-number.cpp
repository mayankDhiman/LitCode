// 1137. N-th Tribonacci Number

class Solution {
public:
    int ch[1000];
    
    int dp(int n){
        if (n < 2) return n;
        if (n == 2) return 1;
        
        if (ch[n] != -1) return ch[n];
        
        return ch[n] = dp(n - 1) + dp(n - 2) + dp(n - 3);
    }
    
    int tribonacci(int n) {
        memset(ch, -1, sizeof ch);
        return dp(n);    
    }
};