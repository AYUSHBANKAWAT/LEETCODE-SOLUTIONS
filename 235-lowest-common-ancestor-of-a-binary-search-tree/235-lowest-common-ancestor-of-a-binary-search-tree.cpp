/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q){
        if( p->val <=root->val and q->val>=root->val )return root;
        if( p->val>root->val )return lca(root->right,p,q);
        if( q->val<root->val )return lca(root->left,p,q);
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if( p->val>q->val )return lowestCommonAncestor(root,q,p);
        return lca(root,p,q);
    }
};