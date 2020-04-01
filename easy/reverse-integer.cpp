class Solution {
public:
    int reverse(int x) {
        if (x >= (long long)INT_MAX or x <= (long long)INT_MIN)   return 0;
        long long reversedInteger = 0;
        long long sign = x, copy = abs(x);
        while (copy > 0){
            reversedInteger = (reversedInteger * 10) + (copy % 10);
            if (reversedInteger >= ((long long) INT_MAX) ){
                return 0;
            }
            copy /= 10;
        }        
        if (sign < 0) reversedInteger = 0 - reversedInteger;
        return reversedInteger;
    }
};


