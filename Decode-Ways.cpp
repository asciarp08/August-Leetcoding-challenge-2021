/**
Time = O(n)
Space = O(1)
**/
class Solution {
public:
    int numDecodings(string s) {
        
        int n = s.size();
        if(s[0]=='0')return 0;
        
        int twoback = 1, oneback = 1;
        
        for(int i = 1; i<n; i++){
            int count = 0;
            if(s[i]!='0')
                count+=oneback;
            
            int num = 0;
            num+=(s[i]-'0');
            num+=(s[i-1]-'0')*10;
            
            if(num%10==0 && num>20)//30, 40, ...
                return 0;
            if(num>=10 && num<=26){
                count+=twoback;
            }
            twoback = oneback;
            oneback = count;
        }
        
        return oneback;    
    }
};
