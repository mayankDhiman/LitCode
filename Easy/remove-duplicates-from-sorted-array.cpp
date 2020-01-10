class Solution {
public:
    int removeDuplicates(vector<int>& nums) {      
        int j = 0;
        nums.push_back(INT_MAX);
        for (int i = 0; i < nums.size() - 1; i ++)
        {
            if (nums[i] < nums[i + 1])
            {
                nums[j] = nums[i];
                j += 1;
            }
        }
        return j;
    }
};