/**
Time complexity: O(mn*log(mn))
Space complexity: O(mn)
**/

class UnionFindTree{
public:   
    unordered_map<int,int>par;
    
    int find(int x){
        return x==par[x]?x:par[x]=find(par[x]);
    }
    
    void unite(int x, int y){
        if(!par.count(x)) par[x] = x;
        if(!par.count(y)) par[y] = y;
        
        int parX = find(x);
        int parY = find(y);
        if(parX==parY)return;
        par[parY] = parX; 
    }
    
    unordered_map<int,vector<int>> getConnectedComponents(){
        unordered_map<int,vector<int>> groups;
        
        for(auto [u,_]:par){
            groups[find(u)].push_back(u);
        }
        return groups;
    }
    
};
class Solution {
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        map<int, vector<pair<int,int>>> groupByNum;
        
        for(int i = 0;i<m;i++){
            for(int j=0; j<n; j++){
                groupByNum[matrix[i][j]].push_back({i,j});
            }
        }
        
        vector<int> maxRank(m+n, 0);
        vector<vector<int>> rank(m,vector<int>(n,0));
        
        for(auto [_, pos]:groupByNum){
            UnionFindTree uft;
            
            for(auto [i,j]: pos){
                uft.unite(i,j+m);
            }
            
            for(auto [_, group]: uft.getConnectedComponents()){
                
                int curRank = 0;
                for(auto i:group){
                    curRank = max(curRank, maxRank[i]);
                }
                
                for(auto i:group){
                    maxRank[i] = curRank+1;
                }
                
            }
            
            for(auto [i,j]:pos){
                rank[i][j] = maxRank[i];
            }
            
        }
        
        
        
        return rank;
        
        
        
    }
};
