// 526. Beautiful Arrangement
// Backtracking based solution

class Solution {
public:
    int n;
    map < pair<int, set <int>> , int> ch; 
    
    int dp(int i, set <int> c){
        if (i == n + 1) 
            return (c.empty());
        if (ch.find({i, c}) != ch.end())    return ch[{i, c}];
        int ret = 0;
        for (auto x : c){
            if ((x % i == 0) || (i % x == 0)){
                set <int> c_;   c_ = c;     c_.erase(x);
                ret += dp(i + 1, c_);
            }
        }
        return ch[{i, c}] = ret;
    }
    
    int countArrangement(int N) {
        n = N;  set <int> c;  for (int i = 1; i <= N; i ++)   c.emplace(i);
        return dp(1, c);          
    }
};
