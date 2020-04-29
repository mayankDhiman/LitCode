class Solution {
public:
    // 1. Make a prefix sum array
    // 2. for each i in (0, n):
    //        res += count[a[i] - k]; 
    int subarraySum(vector<int>& a, int k) {
        int n = a.size(); 
        if (n == 0) return 0;
        vector <int> ps(n + 1); for (int i = 1; i < n + 1; i ++) ps[i] = ps[i - 1] + a[i - 1];
        unordered_map <int, int> cn;
        int res = 0;
        for (int i = 0; i < n + 1; i ++){
            res += cn[ps[i] - k];
            cn[ps[i]] += 1;
        }
        return res;
    }
};
