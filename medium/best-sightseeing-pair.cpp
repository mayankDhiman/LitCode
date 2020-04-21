// 1014. Best Sightseeing Pair

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& a) {
        int cm = a[0] + 0, n = a.size(), ret = -2e9;
        for (int i = 1; i < n; i ++){
            ret = max(ret, cm + a[i] - i);
            cm = max(a[i] + i, cm);
        }
        return ret;
    }
};
