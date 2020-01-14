class Solution {
public:
    string countAndSay(int n) {
        string result = "1";      
        for (int i = 1; i < n; i ++) 
        {      
            string _result = "";       
            for (int i = 0; i < result.size(); ) {
                char pre = result[i];
                int count = 0;
                while((result[i] == pre) && (i < result.size())) {
                    i += 1;
                    count += 1;
                }
                _result += to_string(count);
                _result += string(1, pre);
            }
            result = _result;
        }
        return result; 
    }
};