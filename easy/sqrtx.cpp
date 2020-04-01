class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) return x;
        int lo = 1, hi = 50000;
      
        while (lo < hi) {
            long long md = (lo + hi + 1) / 2;
            if (md * md <= x * 1ll)    {
                lo = md; 
            }  
            else {
                hi = md - 1;
            }
        }
        return lo;
    }
};