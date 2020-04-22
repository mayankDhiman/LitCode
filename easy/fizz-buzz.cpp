// 412. Fizz Buzz

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector <string> ret;
        for (int i = 1; i <= n; i ++){
            bool x = (i % 3 == 0), y = (i % 5 == 0);
            if (x & y){
                ret.emplace_back("FizzBuzz");       
            }else if (x){
                ret.emplace_back("Fizz");
            }else if (y){
                ret.emplace_back("Buzz");
            }else{
                ret.emplace_back(to_string(i));
            }
        }    
        return ret;
    }
};
