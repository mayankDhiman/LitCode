// 204. Count Primes

class Solution {
public:
    int countPrimes(int n) {
        bool sv[n + 1];  memset(sv, 1, sizeof sv);
        for (int i = 2; i < n + 1; i ++){
            if (sv[i]){
                for (int j = i + i; j < n + 1; j += i){
                    sv[j] = 0;
                }
            }
        }        
        int ret = 0; 
        for (int i = 2; i < n; i ++){
            ret += sv[i];
        }
        return ret;
    }
};