class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int curr_min = INT_MAX, result = INT_MIN;
        for (int i = 0; i < prices.size(); i ++) {
            curr_min = min(prices[i], curr_min);
            result = max(prices[i] - curr_min, result);
        }    
        if (result == INT_MIN)  return 0;
        return result;
    }
};