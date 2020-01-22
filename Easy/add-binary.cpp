class Solution {
public:
    string addBinary(string a, string b) {
        string result;
        int i = a.size() - 1, j = b.size() - 1, carry = 0, aa = 0, bb = 0;
        while (i >= 0 || j >= 0 || carry != 0) {
            aa = 0; bb = 0;
            if (i >= 0) aa = a[i] - '0';
            if (j >= 0) bb = b[j] - '0';
            result.insert(result.begin(), '0' + ((aa + bb + carry)%2) );
            carry = (aa + bb + carry) / 2;                            
            i -= 1; j -= 1;
        }
        return result;  
    }
    
};