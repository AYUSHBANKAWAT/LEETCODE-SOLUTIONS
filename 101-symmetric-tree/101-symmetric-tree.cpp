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
    void chk( TreeNode* left,TreeNode*right,bool &b ){
       
        if( !left and !right  )return;
        if( !left or !right  ){
            b=false;
            return;
        }
        if( left->val!=right->val ){
            b=false;
            return;
        }
        if( b ){
        chk(left->left,right->right,b);
        chk(left->right,right->left,b); }
    }
    bool isSymmetric(TreeNode* root) {
       // if( !root )return false;
        bool c=true;
        if( root->left==nullptr and root->right==nullptr )return true;
        chk(root->left,root->right,c);
        return c;
    }
};