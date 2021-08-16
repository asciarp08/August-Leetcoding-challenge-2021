/**
Time = O(1) for each query, O(n) preprocessing time
Space = O(n)
**/

class NumArray {
private:
    vector<int> sum;
public:
    NumArray(vector<int>& nums) {
        sum = nums;
        
        for(int i = 1; i<sum.size(); i++){
            sum[i] = sum[i-1]+nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        if(left==0)
            return sum[right];
        return sum[right] - sum[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
