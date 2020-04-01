// 948. Bag of Tokens

class Solution {
public:
    int bagOfTokensScore(vector<int>& t, int p) {
        int n = t.size();
        sort(t.begin(), t.end());
        int pw = p, pt = 0, i = 0, j = n - 1; 
        int ret = 0;
        while (i <= j){
            if (pw >= t[i]){
                pw -= t[i];
                pt += 1;
                i += 1;        
            }    
            else if (pt > 0){
                pt -= 1;
                pw += t[j];
                j -= 1;
            }
            else{
                break;
            }
            ret = max(ret, pt);
        }
        return ret;
    }
};