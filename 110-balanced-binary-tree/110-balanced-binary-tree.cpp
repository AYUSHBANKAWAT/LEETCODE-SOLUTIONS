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
    int height( TreeNode*r ){
        if(r==nullptr)return 0;
        int left = height(r->left);
        int right = height(r->right);
        return 1+max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        if( root==nullptr )return true;
         int left = height(root->left);
        int right = height(root->right);
        if( abs(left-right)>1 )return false;
        bool l = isBalanced(root->left);
        bool r = isBalanced(root->right);
        if( !l or !r )return false;
        return true;
    }
};