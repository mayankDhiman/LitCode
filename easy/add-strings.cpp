class Solution {
public:
    string addStrings(string num1, string num2) {
        while(num1.size() < num2.size()){
            num1 = "0" + num1;
        }
        while(num2.size() < num1.size()){
            num2 = "0" + num2;
        }
        
        
        int n = num1.size(), rem = 0;    string res(n, '0');

        for (int i = n - 1; i >= 0; i --){
            res[i] = char(  ((num1[i] - '0') + (num2[i] - '0') + rem)%10 + '0' );
            rem = ( (num1[i] - '0') + (num2[i] - '0') + rem) / 10;
        }        
        if (rem > 0){
            res = char(rem + '0') + res;
       }
        
        return res;
    }
};
