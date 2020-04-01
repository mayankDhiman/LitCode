class Solution {
public:
    int n;
    vector < vector < vector <long long> > > cache;
    
    
    long long dp(int i, int e, bool pre){
        if (i == n){
            return 0;
        }
        if (i > n){
            return INT_MAX;
        }
        
        if (cache[i][e][pre] != -1){
            return cache[i][e][pre];
        }
        
        long long r = INT_MAX;
        if (e != 0){
            r = min(1 + dp(i + e, e, 1), r);
        }

        if (pre){
            r = min(1 + dp(i, i, 0), r);
        }
        
        return cache[i][e][pre] = r;
    }
    
    int minSteps(int _n) {
        n = _n; cache.resize(1000, vector <long long> (1000, vector <long long> (2, )));
        return int(dp(1, 0, 1));
    }
};