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
    TreeNode* deleteNode(TreeNode* root, int key) {
       if( root==nullptr )return root;
        if( root->val ==  key ){
            return helper(root);
        }
        TreeNode*dummy = root;
        while( root ){
            if( root->val>key ){
                if( root->left and root->left->val==key ){
                    root->left = helper(root->left);
                    break;
                }else{
                    root=root->left;
                }
            }
            else {
                if( root->right and root->right->val==key ){
                    root->right = helper(root->right);
                    break;
                }else{
                    root=root->right;
                }
            }
        }
        return dummy;
    }
    TreeNode* helper( TreeNode*r ){
        if( !r->left )return r->right;
        else if( !r->right )return r->left;
        TreeNode* m = extremeRight(r->left);
        m->right=r->right;
        return r->left;
    } 
    TreeNode* extremeRight( TreeNode*r ){
        if( !r->right )return r;
        return extremeRight(r->right);
    }
};