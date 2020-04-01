// 718. Maximum Length of Repeated Subarray

class Solution {
public:
    vector <int> a, b;
    int n, m;
    bool ok(int l){
        set <vector <int>> av;
        for (int i = 0; i <= n - l; i ++){
            vector <int> x(a.begin() + i, a.begin() + i + l);
            av.insert(x);
        }
        for (int i = 0; i <= m - l; i ++){
            vector <int> x(b.begin() + i, b.begin() + i + l);
            if (av.find(x) != av.end()){
                return 1;
            }
        }
        return 0;
    }
    
    int findLength(vector<int>& A, vector<int>& B) {
        a = A;  b = B;  n = A.size();  m = B.size();
        int lo = 0, hi = 2e9;
        while (lo < hi){
            int md = lo + (hi - lo + 1)/2;
            if (ok(md)){
                lo = md;
            }
            else{
                hi = md - 1;
            }
        }
        return lo;
    }
};