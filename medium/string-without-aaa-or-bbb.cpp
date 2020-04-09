// 984. String Without AAA or BBB

class Solution {
public:
    string strWithout3a3b(int A, int B) {
        string res1;
        for (int i = 0; i < min(A, B); i ++) {
            res1 += "ab";
        }
        int rem = max(A, B) - min(A, B);
        string ret;
        if (A > B){
            for (int i = 0; i < res1.size(); i ++){
                ret += res1[i];
                if (res1[i] == 'a' && rem > 0){
                    ret += 'a';
                    rem -= 1;
                }
            }
            if (rem > 0){
                while (rem --){
                    ret += 'a';
                }
            }
        }
        else{
            for (int i = 0; i < res1.size(); i ++){
                ret += res1[i];
                if (res1[i] == 'b' && rem > 0){
                    ret += 'b';
                    rem -= 1;
                }
            }
            if (rem > 0){
                while (rem --){
                    ret = 'b' + ret;
                }
            }
        }
        return ret;
    }
};
