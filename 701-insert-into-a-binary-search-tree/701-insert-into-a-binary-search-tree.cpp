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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
       
        if( !root ){
            TreeNode* m = new TreeNode(val);
            return m;
        }
        TreeNode* k = root;
        TreeNode* kt = root;
        
        while( root  ){
            kt=root;
            if( root->val > val ){
                if(root)
                root=root->left;
            }else{
                if(root)
                root=root->right;
            }
        }
        
        if( kt->val>val ){
            kt->left =  new TreeNode(val);
        }
        else{
            kt->right =  new TreeNode(val);
        }
        
        
        return k;
    }
};