int _n;
vector <int> cache(100000, -1);

int solve(int i) {
    if (cache[i] != -1) return cache[i];
    
    if (i == _n)    return 1;
    if (i > _n) return 0;    
    return cache[i] = (solve (i + 2) + solve(i + 1));
}

class Solution {
public:
    int climbStairs(int n) {
        vector <int> _cache(100000, -1);    cache = _cache;
        cache = _cache;
        _n = n;
        return solve(0);      
    }
};