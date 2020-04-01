// 509. Fibonacci Number

class Solution {
public:
    int ch[1000];
    
    int dp(int N){
        if (N < 2) return N;
        if (ch[N] != -1)    return ch[N];    
        return ch[N] = dp(N - 1) + dp(N - 2);
    }
    
    int fib(int N) {
        memset(ch, -1, sizeof ch);
        return dp(N);
    }
};