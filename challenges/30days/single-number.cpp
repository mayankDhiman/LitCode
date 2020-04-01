// 1. Single Number
// Time Complexity - O(n)
// Memory Complexity - O(n)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        multiset <int> pre;
        for (int i = 0; i < nums.size(); i ++){
            if (pre.find(nums[i]) != pre.end()){
                pre.erase(pre.find(nums[i]));
            }
            else{
                pre.insert(nums[i]);
            }
        }
        return *pre.begin();
    }
};