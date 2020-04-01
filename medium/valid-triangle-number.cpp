// 611. Valid Triangle Number

class Solution {
public:
    int triangleNumber(vector<int>& a) {
        sort(a.begin(), a.end());
        int n = a.size(), ret = 0;
        for (int i = 0; i < n; i ++){
            for (int j = i + 1; j < n; j ++){
                int x = a[i], y = a[j];
                int z = x + y;
                int ix = lower_bound(a.begin(), a.end(), z) - a.begin();
                ret += max(0, ix - j - 1);
            }
        }
        return max(0, ret);
    }
};