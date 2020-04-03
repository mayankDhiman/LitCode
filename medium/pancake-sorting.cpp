// 969. Pancake Sorting

class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        vector <int> ret;   vector <int> b = A; sort(b.begin(), b.end());
        int n = A.size(), rp = n - 1;
        while (rp > 0){
            int ix = find(A.begin(), A.end(), b[rp]) - A.begin();            
            vector <int> a_;
            for (int i = ix; i >= 0; i --)  a_.push_back(A[i]);
            for (int i = ix + 1; i < n; i ++)   a_.push_back(A[i]);
            A = a_;
            reverse(A.begin(), A.begin() + rp + 1);
            ret.emplace_back(ix + 1);        
            ret.emplace_back(rp + 1);
            rp -= 1;
        }
        return ret;
    }
};

