/**
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
private:
    long long maxProd = 0;
    long long mod = 1e9+7;
    long long totalSum = 0;
public:
    int maxProduct(TreeNode* root) {
        
        totalSum = dfs(root);
        dfs(root);
        return maxProd%mod;
    }
    
    int dfs(TreeNode* root){
        if(root==NULL)
            return 0;
        
        long long subTreeSum = dfs(root->left) + root->val + dfs(root->right);
        maxProd = max((totalSum-subTreeSum)*subTreeSum, maxProd);
        return subTreeSum;
        
    }
};
