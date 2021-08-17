/**
n = number of vertices 
Time = O(n)
Space = O(n)
**/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int goodNodes(TreeNode* root) {
        
        int goodNode = 0;
        dfs(root, goodNode, root->val);
        return goodNode;
    }
    
    void dfs(TreeNode* root, int& goodNode, int greatSoFar){
        if(root->val>=greatSoFar)
            goodNode++;
        greatSoFar = max(root->val, greatSoFar);
        
        if(root->left!=NULL){
            dfs(root->left, goodNode, greatSoFar);
        }
        
        if(root->right!=NULL){
            dfs(root->right, goodNode, greatSoFar);
        }
            
    }
};
