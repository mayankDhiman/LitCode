// 978. Longest Turbulent Subarray

class Solution {
public:
    int maxTurbulenceSize(vector<int>& a) {
        int n = a.size();
        if (n <= 1) return n;
        vector <int> b(n, -1);
        for (int i = 0; i < n - 1; i ++){
            if (a[i] > a[i + 1])    b[i] = 1;
            if (a[i] < a[i + 1])    b[i] = 0;
        }
        vector <bool> ev(n, 0), od(n, 0);
        for (int i = 0; i < n; i ++){
            if (i%2 == 0){
                if (b[i] == 1)  ev[i] = 1;
            }
            if (i % 2 == 1){
                if (b[i] == 0)  ev[i] = 1;
            }
        }
        for (int i = 0; i < n; i ++){
            if (i%2 == 1){
                if (b[i] == 1)  od[i] = 1;
            }
            if (i % 2 == 0){
                if (b[i] == 0)  od[i] = 1;
            }
        }
        int cr1 = 0, cr2 = 0;   vector <int> vr1(n), vr2(n);
        for (int i = 0; i < n; i ++){
            if (ev[i] == 1){
                cr1 += ev[i];
            }
            else{
                cr1 = 0;
            }
            vr1[i] = cr1;
            if (od[i] == 1)
                cr2 += od[i];
            else{
                cr2 = 0;
            }
            vr2[i] = cr2;
        }
        int r1 = *max_element(vr1.begin(), vr1.end());
        int ix; 
        for (int i = 0; i < n; i ++){
            if (vr1[i] == r1){
                ix = i;
                break;
            }
        }
        r1 += (ix != n - 1);        
        int r2 = *max_element(vr2.begin(), vr2.end());
        for (int i = 0; i < n; i ++){
            if (vr2[i] == r2){
                ix = i;
                break;
            }
        }
        r2 += (ix != n - 1);        
        return max(r1, r2);
    }
};


// 1 1 0 1  0 - 1 0 
    
