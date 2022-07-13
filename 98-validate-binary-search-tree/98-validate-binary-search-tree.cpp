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
    bool validation( TreeNode*root,long min,long max ){
        if( !root )return true;
        if(min>=root->val or max<=root->val)return false;
    return validation(root->left,min,root->val) and validation(root->right,root->val,max);
        
    }
    bool isValidBST(TreeNode* root) {
        return validation(root,LLONG_MIN,LLONG_MAX);
    }
};