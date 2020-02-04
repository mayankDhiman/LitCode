class Solution {
public:
    int sqSum(int n) {
        int res = 0;
        while(n > 0){
            res += (n%10) * (n%10);
            n /= 10;
        }
        return res;
    }
    
    bool isHappy(int n) {
        set <int> already;
        while(1){
            n = sqSum(n);
            if (n == 1) return true;
            if ( already.find(n) != already.end()  ) {
                return false;
            }
            already.insert(n);            
        }
    }
};
