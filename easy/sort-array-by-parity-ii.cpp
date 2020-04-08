// 922. Sort Array By Parity II


class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        vector <int> ret(A.size());
        int od = 1, ev = 0;
        for (auto x : A) {
            if (x % 2){
                ret[od] = x;
                od += 2;
            }
            else{
                ret[ev] = x;
                ev += 2;
            }
        }
        return ret;
    }
};
