// Array of Doubled Pairs

class Solution {
public:
    bool canReorderDoubled(vector<int>& a) {
        map <int, int> pos;
        map <int, int, greater <int> > neg; 
        int n = a.size();
        for (int i = 0; i < n; i ++){
            if (a[i] > 0)   pos[a[i]] += 1;
            else    neg[a[i]] += 1;
        }
        bool ok = 1;
        for (auto x : pos){
            int k = x.first, v = x.second;
            if (v > 0){
                if (pos[2*k] < v){
                    ok = 0;
                    break;
                }
                pos[k] -= 0;
                pos[2*k] -= v;                
            }
        }
        for (auto y : neg){
            int k = y.first, v = y.second;
            if (v > 0){
                if (neg[2*k] < v){
                    ok = 0;
                    break;
                }
                neg[k] -= 0;
                neg[2*k] -= v;
            }
        }
        return ok;
    }
};