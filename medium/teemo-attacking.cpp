// 649. Dota2 Senate

class Solution {
public:
    string predictPartyVictory(string senate) {
        queue <int> q;
        for (auto c : senate){
            if (c == 'R')   q.push(0);
            else    q.push(1);
        }
        int br = 0, bd = 0, cr = count(senate.begin(), senate.end(), 'R'), cd = count(senate.begin(), senate.end(), 'D');
        while(1) {
            int x = q.front();  q.pop();
            if (x == 1){
                if (cr == 0)    return "Dire";       
                if (bd == 0){
                    br += 1;
                    cr -= 1;
                    q.push(x);
                }
                else    bd -= 1;
            }
            else {
                if (cd == 0)    return "Radiant";
                if (br == 0){
                    bd += 1;
                    q.push(x);
                    cd -= 1;
                }
                else    br -= 1;
            }
        }
        return "";
    }
};
