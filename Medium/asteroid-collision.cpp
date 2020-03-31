// 735. Asteroid Collision

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroid) {
        int n = asteroid.size();
        stack <int> a;
        for (int i = 0; i < n; i ++)
        {
            int x = asteroid[i];
            while (abs(x) > 0){
                if (a.empty()){
                    a.push(x);
                    x = 0;
                    break;
                }
                if (a.top() * x > 0){
                    a.push(x);
                    x = 0;
                    break;
                }
                
                if ((a.top() > 0) && (x < 0) ){
                    if (abs(a.top()) > abs(x) ){
                        x = 0;
                    }   
                    else if (abs(a.top()) == abs(x)){
                        a.pop();
                        x = 0;
                    }
                    else{
                        a.pop();   
                    }                    
                }
                else{
                    a.push(x);
                    break;
                }

            }
        }
        vector <int> ret;
        while (!a.empty()){
            ret.push_back(a.top());
            a.pop();
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};