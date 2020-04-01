class Solution {
public:
    int balancedStringSplit(string s) {
        int numberBalanced = 0, lcount = 0, rcount = 0;
        
        for (int i = 0; i < s.size(); i ++)
        {
            if (s[i] == 'L')    lcount += 1;
            else    rcount += 1;
            
            if (lcount == rcount && i != 0){
                numberBalanced += 1;
                lcount = 0;
                rcount = 0;
            }
        }
        
        return numberBalanced;
    }
};