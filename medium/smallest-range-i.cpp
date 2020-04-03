// 908. Smallest Range I

class Solution {
public:
    int smallestRangeI(vector<int>& A, int k) {
        int mn = *min_element(A.begin(), A.end()), mx = *max_element(A.begin(), A.end()); 
        return max(0, (mx - k) - (mn + k));
    }
};
