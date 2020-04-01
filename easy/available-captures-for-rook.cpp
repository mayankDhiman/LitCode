// 999. Available Captures for Rook

class Solution {
public:
    int numRookCaptures(vector<vector<char>>& a) {
        int px, py;
        for (int i = 0; i < 8; i ++){
            for (int j = 0; j < 8; j ++){
                if (a[i][j] == 'R'){
                    px = i; py = j; break;
                }
            }
        }
        int res = 0;
        
        int i = px + 1, j = py;
        while (i < 8){
            if (a[i][j] == 'B'){
                break;
            }
            if ( a[i][j] == 'p' ){
                res += 1;
                break;
            }
            i += 1;
        }

        i = px - 1; j = py;
        while (i >= 0){
            if ( a[i][j] == 'B' ){
                break;
            }
            if ( a[i][j] == 'p' ){
                res += 1;
                break;
            }
            i -= 1;
        }

        i = px; j = py + 1; 
        while (j < 8){
            if ( a[i][j] == 'B' ){
                break;
            }
            if ( a[i][j] == 'p' ){
                res += 1;
                break;
            }
            j += 1;
        }
        
        i = px; j = py - 1;
        while (j >= 0){
            if ( a[i][j] == 'B' ){
                break;
            }
            if ( a[i][j] == 'p' ){
                res += 1;
                break;
            }
            j -= 1;
        }
        
        return res;
    }
};