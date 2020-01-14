    vector <string> result;
    int _n;
    
    void doo(string current, stack <char> stk) {
        if (current.size() == 2*_n){
            if (stk.size() == 0){
                result.push_back(current);
            }
        } 

        else{
            stack <char> stk1 = stk, stk2 = stk;
            
            stk1.push('(');
            
            if (stk2.size() == 0)   stk2.push(')');
            else {
                if (stk2.top() == '(')  stk2.pop();
                else    stk2.push(')');
            }
            
            
            doo(current + "(", stk1);
            doo(current + ")", stk2);
        }
    }
    
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        ::_n = n;
        result.clear();
        stack <char> stk;
        doo("", stk);    
        return result;
    }
};