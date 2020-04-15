class Solution {
public:
    bool find132pattern(vector<int>& a) {
        int n = a.size();
        vector <pair <int, int>> foo(n, {-1, -1});
        
        int curr = INT_MAX;
        vector <bool> fnd(n, 0);

        for (int i = 0; i < n; i ++)
        {
            if (curr < a[i]){
                fnd[i] = true;
                foo[i].first = curr;
            }
            curr = min(curr, a[i]);
        }
                
        set <int> pst;  bool ok = 0;
        for (int i = n - 1; i >= 0; i --)
        {
            int se = a[i], fr = foo[i].first;
            if (pst.upper_bound(fr) != pst.end() && fnd[i]){
                if (*pst.upper_bound(fr) < se){
                    ok = 1;
                }
            }

            pst.insert(a[i]);
        }
        
        return ok;
    }
};
