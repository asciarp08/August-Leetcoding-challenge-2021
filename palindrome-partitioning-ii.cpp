//Time = O(n*n)
//space = O(n*n+n)

/**
cuts[i] represent the minimum cuts we have to make for string start 0 and ending i
to get the palindromic partitions
**/

class Solution {
public:
    int minCut(string s) {
        
        int n = s.size();
        
        vector<vector<bool>>isPalin(n,vector<bool>(n,false));
        
        vector<int> cuts(n,n);
               
        for(int end = 0; end<n; end++){
            for(int start = end; start>=0; start--){
                
                if( s[start]==s[end] && ( end-start<2 || isPalin[start+1][end-1])){
                    isPalin[start][end] = true;
                    cuts[end] = min(cuts[end], start==0?0:cuts[start-1]+1);
                }
            }
        }
        
        return cuts[n-1];
    }
};
