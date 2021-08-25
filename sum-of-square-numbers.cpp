/**
Time = O(n), n = sqrt(c)
Space = O(1)
**/
class Solution {
public:
    bool judgeSquareSum(int c) {
        long long l = 0, r = sqrt(c);
        
        while(l<=r){
            long long sum = l*l+r*r;
            if(sum>c*1LL){
                r--;
            }
            else if(sum<c*1LL){
                l++;
            }
            else{
                return true;
            }
        }
        return false;
    }
};
