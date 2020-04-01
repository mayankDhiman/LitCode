class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector <vector <int> > result(numRows);
        if (numRows == 0){
            return result;
        }
        vector <int> pre{1};
        result[0] = pre;
        for (int i = 1; i < numRows; i ++) {            
            vector <int> now(i + 1, 0);
            for (int j = 0; j < i + 1; j ++) {
                if (j == 0 || j == i)   now[j] = 1;
                else {
                    now[j] = pre[j] + pre[j - 1];
                }
            }
            result[i] = now;
            pre = now;
        }
        return result;
    }
};