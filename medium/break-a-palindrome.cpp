// 1328. Break a Palindrome

class Solution {
public:
    string breakPalindrome(string a) {
        int n = a.size();
        if (n == 1) return "";
        bool ok = 0;
        for (int i = 0; i < (n / 2); i ++) {
            if (a[i] != 'a'){
                a[i] = 'a';
                ok = 1;
                break;
            }
        }
        if (!ok){
            a[n - 1] = 'b';
        }
        return a;
    }
};
