/**
Time - O(len), len = ops.size()
Space - O(1)
**/

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int minRow = m, minCol = n;
        
        for(auto v:ops){
            minRow=min(minRow, v[0]);
            minCol= min(minCol, v[1]);
            
        }
        return minRow*minCol;
    }
};
