#include <bits/stdc++.h>

class Solution {
public:
    string a;   int n;      vector <int> cache;
    
    int dp(int i){
        if (i >= n)
            return 1;
        if (cache[i] != -1) return cache[i];
        int r1 = 0, r2 = 0;
        if (stoi(a.substr(i, 1)) != 0)  r1 = dp(i + 1);
        string _r2 = a.substr(i, 2);        
        if (_r2.size() == 2){
            if (stoi(_r2) <= 26 && stoi(_r2) >= 10)    r2 = dp(i + 2);
        }      
        return cache[i] = r1 + r2;
    }
    
    int numDecodings(string s) {
        a = s;  n = s.size();   vector <int> _cache(100000, -1);    cache = _cache;
        return dp(0);
    }
};