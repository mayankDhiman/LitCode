class Solution {
public:
    int threeSumMulti(vector<int>& a, int target) {
        int res = 0, n = a.size(), mod = 1000000007;
        for (int i = 0; i < n; i ++){
            int t1 = target - a[i];
            if (t1 >= 0){
                int count[400] = {0};
                for (int j = i + 1; j < n; j ++){
                    int t2 = t1 - a[j];
                    if (t2 >= 0){
                        res = (res + count[t2] % mod) % mod;
                        count[a[j]] += 1;                        
                    }
                }                
            }
        }
        return res;      
    }
};