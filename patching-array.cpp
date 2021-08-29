/**
Time = O(m+logn) m = nums.size()
Space = O(1)
**/

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int m = nums.size();
        
        long long maxSum = 0;
        int patches = 0;
        int i = 0;
        
        while(maxSum<n){
            if(i<m && maxSum+1>=nums[i]){
                maxSum+=nums[i]*1LL;
                i++;
            }
            else{
                maxSum+=maxSum+1;
                patches++;
            }
        }
        return patches;
    }
};
