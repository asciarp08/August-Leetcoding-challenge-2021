/**
Time = O(klogk * n)
Space = O(n*k)
n is the number of strings in strs
k is the size of the largest string in strs
**/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<int>>groups;
        
        for(int i = 0; i<strs.size(); i++){
            string t = strs[i];
            sort(t.begin(), t.end());
            
            groups[t].push_back(i);
        }
        
        vector<vector<string>>ans;
        
        for(auto [_, pos]:groups){
            vector<string>tmp;
            
            for(auto i:pos){
                tmp.push_back(strs[i]);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};
