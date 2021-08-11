/**
Time = O(n)
Space = O(1)
**/

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        
        int cntFlip = 0;
        int cntOne = 0;
        
        for(int i = 0; i<s.size(); i++){
            if(s[i]=='0'){
                if(cntOne)
                    cntFlip++;
                
            }
            else{
                cntOne++;
            }
            
            cntFlip = min(cntOne, cntFlip);
        }
        
        return cntFlip;
    }
};


/**
Time = O(2n)
Space = O(n)
**/
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        vector<int> cnt(n+1,0);
        
        for(int i = 0; i<n;i++){
            cnt[i+1]+=s[i]=='0'?1:0;
            cnt[i+1]+=cnt[i];
            
        }
        
        int ans = n;
        for(int i = 1; i<=n+1; i++){
            //make 0 before i, and 1 after i
            
            int zeroBefore = cnt[i-1]-cnt[0];
            int zeroAfter = cnt[n]-cnt[i-1];
            // cout << i << " " << zeroBefore << "  " << zeroAfter << endl;
            ans = min(ans, i-1-zeroBefore+zeroAfter);
        }
        return ans;
    }
};
