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

    private :
    TreeNode*pre;
    TreeNode*first;
    TreeNode*last;
    TreeNode*middle;
    
    void inorder(TreeNode*root){
        if( !root )return;
        inorder(root->left);
        if( pre and (root->val<pre->val) ){
            if (!first){
                first=pre;
                middle=root;
            }
            else{
                last = root;
            }
        }
        pre=root;
        inorder(root->right);
    }
    
    public:
    
    
    void recoverTree(TreeNode* root) {
        last=first=middle=nullptr;
        pre=new TreeNode(INT_MIN);
        inorder(root);
        if( first and last )swap(first->val,last->val);
        else if(first and middle)swap(first->val,middle->val);
        
    }
};