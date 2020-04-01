// 1310. XOR Queries of a Subarray

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector <int> px(n + 1);
        for (int i = 1; i < n + 1; i ++)    px[i] = px[i - 1] ^ arr[i - 1];        
        int rn = queries.size(); 
        vector <int> ret(rn);
        int i = 0;
        for (auto q : queries){
            int l = q[0], r = q[1];
            ret[i] = px[r + 1] ^ px[l];
            i += 1;
        }
        return ret;
    }
};