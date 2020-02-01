class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0, i = digits.size() - 1;
        
        if (digits.size() == 0){
            vector <int> one{1};
            return one;
        }
        
        do {
            if (i == digits.size() - 1) digits[i] += 1;
            else    digits[i] += carry;

            carry = digits[i] / 10;
            digits[i] = digits[i] % 10;
            i -= 1;
        }
        while(i >= 0 && carry != 0);
            
        if (carry != 0 && i == -1)   digits.insert(digits.begin(), 1);

        return digits;
    }
    
};