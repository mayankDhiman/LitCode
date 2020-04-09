// 1300. Sum of Mutated Array Closest to Target


class Solution {
public:
    int findBestValue(vector<int>& a, int t) {
        int n = a.size();   sort(a.begin(), a.end());
        vector <int> ps(n + 1); int mn = 2e9, ret;
        for (int i = 1; i < n; i ++)    ps[i] = ps[i - 1] + a[i - 1];
        for (int ht = 0; ht <= a[n - 1]; ht ++) {
            int ix = lower_bound(a.begin(), a.end(), ht) - a.begin();
            int cn = n - ix;
            int sm = ps[ix] + cn * ht;
            if ( abs(sm - t) < mn ){
                mn = abs(sm - t);
                ret = ht;
            }
        }
        return ret;
    }
};
