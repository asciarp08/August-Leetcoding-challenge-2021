/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root==NULL)return vector<vector<int>>();
        
        vector<vector<int>>levels;
        queue<Node*> nodes;
        nodes.push(root);
        
        while(!nodes.empty()){
            int cur_size = nodes.size();
            vector<int>cur_level;
            
            while(cur_size--){
                Node* cur_node = nodes.front(); nodes.pop();
                cur_level.push_back(cur_node->val);
                
                for(auto children:cur_node->children){
                    nodes.push(children);
                }
            }
            
            levels.push_back(cur_level);
        }
        
        return levels;
        
    }
};
