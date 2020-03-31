// 881. Boats to Save People

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int n = people.size();
        int i = 0, j = n - 1, ret = 0;
        while (i < j){
            if (people[i] + people[j] <= limit){
                ret += 1;
                i += 1;
                j -= 1;
            }
            else{
                ret += 1;
                j -= 1;
            }
        }        
        return ret + (i == j);
    }
};