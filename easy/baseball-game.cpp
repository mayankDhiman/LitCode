// 682. Baseball Game

class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector <int> valid_points;
        for (auto& each : ops) {
            if (each == "+") {
                if (valid_points.size() >= 2) {
                    valid_points.emplace_back(valid_points[valid_points.size() - 1] +                                              valid_points[valid_points.size() - 2]);
                }
            }
            else if (each == "D") {
                if (valid_points.size() >= 1) {
                    valid_points.emplace_back(2 * valid_points[valid_points.size() -                                              1]);
                }
            }
            else if (each == "C") {
                if (valid_points.size() >= 1) {
                    valid_points.erase(valid_points.begin() + valid_points.size() - 1);
                }
            }
            else {
                valid_points.emplace_back(stoi(each));
            }
        }
        
        return accumulate(valid_points.begin(), valid_points.end(), 0);
    }
};
