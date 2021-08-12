/**
Time = O(n*(k+c))
Space = O(n*(k+c))
n is the number of strings in strs
k is the size of the largest string in strs
c is for characters in count string- which will have the count of characters stored
**/


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string,int> groupId; //count string-key, groupId-value
        vector<vector<string>> groups;
        int idx = 0;
        
        for(auto s:strs){
            
            string t = "";
            vector<int> charCount(26,0);
            for(auto c:s){
                charCount[c-'a']++;
            }
            for(int i= 0; i<26; i++){
                t+=to_string(charCount[i]);
                t+="#";
            }
            
            if(groupId.count(t)){
                groups[groupId[t]].push_back(s);
            }
            else{
                groupId[t] = idx;
                vector<string> newGroup;
                newGroup.push_back(s);
                groups.push_back(newGroup);
                idx++;
            }
            
        }
        
        return groups;
        
    }
};









/**
Time = O(klogk * n)
Space = O(n*k)
n is the number of strings in strs
k is the size of the largest string in strs
**/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,int> groupId;
        
        vector<vector<string>>groups;
        int idx = 0;
        for(auto s:strs){
            string t = s;
            sort(t.begin(), t.end());
            if(groupId.count(t)){
                groups[groupId[t]].push_back(s);
            }
            else{
                vector<string> newGroup;
                newGroup.push_back(s);
                groups.push_back(newGroup);
                groupId[t] = idx;
                idx++;
            }
        }
        return groups;
    }
};
