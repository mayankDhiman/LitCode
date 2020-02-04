class NumArray {
public:
    vector <int> nums;
    vector <int> prSum;
    
    NumArray(vector<int>& nums) {
        nums = nums;
        prSum.resize(nums.size() + 1);
        for (int i = 1; i < prSum.size(); i ++){
            prSum[i] = prSum[i - 1] + nums[i - 1];
        }
    }
    
    int sumRange(int i, int j) {
        return prSum[j + 1] - prSum[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
