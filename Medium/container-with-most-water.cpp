class Solution {
public:
    int maxArea(vector<int>& height) {
        vector < pair <int, int> > _height; int n = height.size();
        for (int i = 0; i < n; i ++)    _height.push_back({height[i], i});
       
        sort(_height.begin(), _height.end());
       
        vector < pair <int, int> > mxmn(n); int _mx = INT_MIN, _mn = INT_MAX;
        for (int i = n - 1; i > -1; i --) {
            _mx = max(_mx, _height[i].second);
            _mn = min(_mn, _height[i].second);
            mxmn[i].first = _mn;
            mxmn[i].second = _mx;
        }
        
        int result = INT_MIN;
        for (int i = n - 2; i > -1; i --) {
            result =  max(result, max( _height[i].first * abs(mxmn[i + 1].first - _height[i].second), _height[i].first * abs(mxmn[i + 1].second _height[i].second) ) );
        }
        return result;
    }
};