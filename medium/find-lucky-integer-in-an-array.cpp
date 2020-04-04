// 1394. Find Lucky Integer in an Array

class Solution {
public:
    int findLucky(vector<int>& arr) {
        map <int, int, greater <> > cn;
        for (auto &i : arr) cn[i] += 1;
        for (auto &i : cn) {
            if (i.first == i.second){
                return i.first;
            }
        }
        return -1;
    }
};
