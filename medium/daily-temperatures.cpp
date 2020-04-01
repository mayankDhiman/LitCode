class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector <int> res(T.size()); int n = T.size();

        vector <int> next(101, -1);
        
        for (int i = n - 1; i >= 0; i --) {
            
            int curr = INT_MAX;
            for (int t = T[i] + 1; t <= 100; t ++){
                if (next[t] != -1)    curr = min(curr, next[t]);
            }
            
            if (curr == INT_MAX){
                res[i] = 0;
            }
            else{
                res[i] = (curr - i);
            }
            
            next[T[i]] = i;
        }
        
        return res;
    }
};
