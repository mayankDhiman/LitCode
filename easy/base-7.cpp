// 504. Base 7

class Solution {
public:
    string convertToBase7(int num) {
        bool neg = (num < 0);
        string ret;
        num = abs(num);
        while (num > 0) {
            ret = char('0' + (num%7)) + ret;
            num /= 7;
        }        
        if (ret.size() == 0)    ret += '0';
        if (neg)    { ret = "-" + ret; }
        return ret;
    }
};
