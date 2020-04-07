// 1005. Maximize Sum Of Array After K Negations

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& a, int k) {
        multiset <int> pos, neg;
        int sm = 0;
        for (auto j : a){
            sm += j;
            if (j >= 0)  pos.insert(j);  else    neg.insert(j);
        }
        for (int i = 0; i < k; i ++) {
            if (neg.size() > 0) {
                sm +=   - 2 * (*neg.begin());
                pos.insert(- (*neg.begin()));
                neg.erase(neg.begin());
            }            
            else{
                cout << "B\n";
                sm += - 2 * (*pos.begin()) ;
                neg.insert(- (*pos.begin()));
                pos.erase(pos.begin());
            }           
            cout << sm << "\n";
        }
        return sm;
    }
};
