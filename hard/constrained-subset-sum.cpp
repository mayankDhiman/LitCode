// 1425. Constrained Subset Sum

class Solution {
public:
    int constrainedSubsetSum(vector<int>& a, int k) {
        int ret = 0, n = a.size(); vector <int> dp(n);
        multiset <int> pr;
        for (int i = 0; i < n; i ++){
            if (i >= k + 1) pr.erase(pr.find(dp[i - k - 1]));
            dp[i] = a[i];
            if (pr.size() > 0)
                if (*pr.rbegin() + dp[i] > dp[i])   dp[i] = *pr.rbegin() + dp[i];
            pr.insert(dp[i]);
        }
        return *max_element(dp.begin(), dp.end());
    }
};
