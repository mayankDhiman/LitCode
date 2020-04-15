class Solution {
public:
    
    vector <int> cache;
    int n;
    string b;

    bool dp(int i){
        if (i == n - 1){
            return (b[i] == '0');
        }
        if (i > n - 1){
            return 0;
        }
        
        
        if (cache[i] != -1) return cache[i];
        
        
        bool r1 = 1, r2 = 1;
        if (b.substr(i, 2) == "10" || b.substr(i, 2) == "11"){
            r1 = dp(i + 2);
        }
        
        if (b.substr(i, 1) == "0"){
            r2 = dp(i + 1);
        }
        return cache[i] = (r1 & r2);
    }
    
    
    
    bool isOneBitCharacter(vector<int>& bits) {
        n = bits.size();
        cache.resize(10000, -1);
        for (auto i : bits){
            b += '0' + i;
        }        
        return dp(0);
    }
};
