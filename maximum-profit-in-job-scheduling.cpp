/**
Time = O(nlogn)
Space = O(n)
**/

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
        int n = profit.size();
        using ti = tuple<int,int,int>;
        vector<ti> jobs;
        
        for(int i = 0; i<n;i++){
            jobs.push_back({endTime[i], startTime[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end());
        
        map<int,int>maxProfit = {{0,0}};
        int lastTime = 0;
        
        for(int i = 0;i <n; i++){
            auto [e,s,p] = jobs[i];
            int curProfit = (--maxProfit.upper_bound(s))->second+p;
            
            if(curProfit>maxProfit[lastTime]){
                maxProfit[e] = curProfit;
                lastTime = e;
            }
        }
        return maxProfit[lastTime];
        
    }
};
