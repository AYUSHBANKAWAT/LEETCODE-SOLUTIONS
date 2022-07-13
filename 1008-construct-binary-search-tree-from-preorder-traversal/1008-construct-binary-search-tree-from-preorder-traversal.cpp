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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode*root = new TreeNode(preorder[0]);
        for( int i=1;i<preorder.size();i++ ){
            //TreeNode * t = new TreeNode(preorder[i]);
            TreeNode * p=root;
            int val = preorder[i];
            while( p ){
                if( p->val >val  ){
                    if(p->left)p=p->left;
                    else {
                        p->left = new TreeNode(val);
                        break;
                    }
                }
                if( p->val<val ){
                    if(p->right )p=p->right;
                    else{
                        p->right = new TreeNode(val);
                        break;
                    }
                }
            }
        }
        return root;
    }
};