/**
Time - O(n)
Space - O(n)
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
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int,int> vis;
        return dfs(root, vis, k);
    }
    
    bool dfs(TreeNode* root, unordered_map<int,int>& vis, int& k){
        
        if(root==NULL)
            return false;
        
        if(vis.count(k-root->val))
            return true;
        vis[root->val]=1;
        return dfs(root->left, vis, k) || dfs(root->right, vis, k);
    }
};
