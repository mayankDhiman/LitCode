// 974. Subarray Sums Divisible by K

class Solution {
public:
    int subarraysDivByK(vector<int>& a, int k) {
        map <int, int> cn;
        int n = a.size();
        if (n == 0) return 0;
        cn[0] += 1;
        cn[(a[0]%k + k)%k] += 1;
        for (int i = 1; i < n; i ++){
            a[i] = a[i - 1] + a[i];
            cn[(a[i]%k + k)%k] += 1;
        }
        int ret = 0;        
        for (auto xx : cn){
            int x = xx.second;
            ret += x * (x - 1) / 2;
        }
        return ret;
    }
};
