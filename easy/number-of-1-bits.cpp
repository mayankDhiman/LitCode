// 191. Number of 1 Bits

class Solution {
public:
    int hammingWeight(uint32_t n) {
        // __builtin_popcount(n);  Builtin Function.
        int ret = 0;
        while (n != 0){
            n &= (n - 1); // Flipping the least significant set bit trick.
            ret += 1;
        }
        return ret;
    }
};