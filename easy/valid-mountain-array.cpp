class Solution {
public:
    bool down(vector <int> A, int j){
        for (int i = j + 1; i < A.size(); i ++){
            if (A[i] >= A[i - 1]){
                return 0;
            }
        }
        return 1;
    }
    
    bool validMountainArray(vector<int>& A) {
        if (A.size() <= 2)  return 0;
        
        for (int i = 1; i < A.size(); i ++){
            if ( (A[i] <= A[i - 1]) && (i == 1))   return 0;
            
            if (A[i] == A[i - 1])   return 0;
            
            if (A[i] < A[i - 1]){
                return down(A, i);
            }
            
            if (i == A.size() - 2){
                return down(A, i);
            }
        }
        
        return 1;
    }
};
