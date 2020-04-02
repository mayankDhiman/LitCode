// Happy Number

class Solution {
public:
    bool isHappy(int n) {
        bool ok = 1;
        set <int> pr;   pr.insert(n);
        while (n != 1){
            int nn = 0;
            while (n > 0){
                nn += (n%10) * (n%10);
                n /= 10;
            }
            n = nn;
            if (pr.find(n) != pr.end()){
                ok = 0;
                break;
            }
            pr.insert(n);
        }
        return ok;
    }
};