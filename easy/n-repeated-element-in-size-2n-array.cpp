// 961. N-Repeated Element in Size 2N Array

class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        for (int i = 0; i < A.size(); i ++){
            for (int k = 1; k <= 3; k ++){
                if (i + k < A.size()){
                    if (A[i] == A[i + k]){
                        return A[i];
                    }
                }
            }
        }
        return -1;
    }
};