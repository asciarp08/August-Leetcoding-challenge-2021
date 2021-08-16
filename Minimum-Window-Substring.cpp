/**
Time = O(n+m)
Space = O(1) 
**/

class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();
        
        if(m<n || n==0)
            return "";
        
        
        unordered_map<int,int> cnt;
        int required = 0; // required unique characters
        
        for(auto c:t){
            cnt[c]++;
            if(cnt[c]==1)required++;
        }
        
        int start = 0, end = 0;
        int len = INT_MAX, startIdx = -1;
        
        while(start<=end && end<m){
            cnt[s[end]]--;
            if(cnt[s[end]]==0)required--;
            
            while(required==0 && start<=end){
                
                if(len>end-start+1){
                    len = end-start+1;
                    startIdx = start;
                }
                
                cnt[s[start]]++;
                if(cnt[s[start]]>0)
                    required++;
                start++;
            }
            end++;
        }
        
        if(startIdx==-1)
            return "";
        
        return s.substr(startIdx, len);
        
        
    }
};
