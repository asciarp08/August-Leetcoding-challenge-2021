/**
Time = O(n)
Space = O(n)
**/


class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        
        unordered_map<int,int> cnt;
        
        auto comp = [&](const int a, const int b){
            return abs(a)<abs(b);    
        };
        
        
        sort(arr.begin(), arr.end(), comp);
        
        //-1,2,3,4,-2,6
        //-1,2,-2,3,4,6
        
        for(auto num:arr){
            cnt[num]++;
        }
        
        for(auto num:arr){
            if(cnt[num]==0)continue;
            if(cnt[2*num]==0)return false;
            cnt[num]--;
            cnt[2*num]--;
            
        }
        return true;
    }
};
