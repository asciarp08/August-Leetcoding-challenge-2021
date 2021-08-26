/**
Approach 1:
Time = O(n)
Space = O(1)
**/

class Solution {
public:
    bool isValidSerialization(string preorder) {
        int emptySpaces = 1;
        
        preorder+=',';
        
        for(int i = 0; i<preorder.size(); i++){
            if(preorder[i]!=',')continue;
            
            emptySpaces-=1;
            if(emptySpaces<0)
                return false;
            if(preorder[i-1]!='#'){
                emptySpaces+=2;
            }
        }
        return emptySpaces==0;
        
    }
};

/**
Approach 2:
Time = O(n)
Space = O(n)
**/

class Solution {
public:
    bool isValidSerialization(string preorder) {
        stack<char> st;
        preorder+=',';
        
        for(int i = 0; i<preorder.size(); i++){
            if(preorder[i]!=',')continue;
            
            bool flag = 0;
            while(st.size() && st.top()=='#' && preorder[i-1]=='#'){
                flag = true;
                st.pop();
                if(st.size()==0)
                    return false;
                st.pop();
            }
            
            
            st.push(preorder[i-1]);
        }

        
        return st.size()==1&&st.top()=='#';
    }
};
