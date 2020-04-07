// Counting Elements

class Solution {
public:
    int countElements(vector<int>& arr) {
        map <int, int> cn;
        for (int i = 0; i < arr.size(); i ++)   cn[arr[i]] += 1;
        int ret = 0;
        for (auto x : cn) {
            if (cn.find(x.first + 1) != cn.end())
                ret += x.second;
        }
        return ret;
    }
};
