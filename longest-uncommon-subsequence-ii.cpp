/**
Time - O(m*n^2), m = average size of strs[i], n = strs.size()
Space - O(1)
**/



class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        int n = strs.size();
        int maxLen = -1;
        
        auto mycomp = [&](const string s, const string t){
          return s.size()==t.size()?s<t:s.size()<t.size();  
        };
        sort(strs.begin(), strs.end(), mycomp);
        
        for(int i = 0; i<n; i++){
            //to handle duplicates
            bool duplicateFound = 0;
            while(i<n-1 && strs[i]==strs[i+1]){
                i++;
                duplicateFound = 1;
            }
            if(duplicateFound){
                continue;
            }
            bool common = 0;
            for(int j = i+1; j<n; j++){
                if(isSubsequence(strs[i], strs[j])){
                    common = 1;
                    break;
                }
            }
            
            if(!common){
                maxLen = max(maxLen, (int)strs[i].size());
            }
            
        }
        return maxLen;
    }
    
    bool isSubsequence(string s, string t){
        int m = s.size();
        int n = t.size();
        int i = 0, j = 0;
        
        while(i<m && j<n){
            if(s[i]==t[j]){
                i++;
                j++;
            }
            else j++;
        }
        return i==m;
    }
};
