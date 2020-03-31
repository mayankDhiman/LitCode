122. Best Time to Buy and Sell Stock II

class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size(),ret = 0;
        for (int i = 1; i < n; i ++){
            if (p[i] > p[i - 1])    ret += p[i] - p[i - 1];
        }
        return ret;
    }
};