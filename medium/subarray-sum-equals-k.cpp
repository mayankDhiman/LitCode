// 560. Subarray Sum Equals K

class Solution {
public:
    int subarraySum(vector<int>& a, int k) {
        int n = a.size();   map <int, int> pr;
        vector <int> pa(n + 1);
        for (int i = 1; i < n + 1; i ++){
            pa[i] = a[i - 1] + pa[i - 1];
        }
        int ret = 0;
        for (int i = 0; i < n + 1; i ++){
            ret += pr[pa[i] - k];
            pr[pa[i]] += 1;
        }
        return ret;
    }
};
