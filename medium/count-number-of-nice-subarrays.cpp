// 1248. Count Number of Nice Subarrays

class Solution {
public:
    int numberOfSubarrays(vector<int>& a, int k) {
        int n = a.size();   vector <int> b;
        for (int i = 0; i < n; i ++) {
            if (a[i] % 2 == 1)  b.emplace_back(i);
        }
        if (b.size () < k) return 0;
        int ret = 0;
        for (int i = 0; i <= b.size() - k; i ++){
            int ex1 = b[i], ex2 = b[i + k - 1];
            int ex11 = 0, ex22 = n - 1;
            if (i > 0)  ex11 = b[i - 1] + 1;
            if (i + k < b.size())  ex22 = b[i + k] - 1;
            int p1 = ex1 - ex11 + 1;
            int p2 = ex22 - ex2 + 1;
            ret += p1 * p2;
        }
        return ret;
    }
};


