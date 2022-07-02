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
    int maxPath( TreeNode*r,int & m ){
        if( r==nullptr )return 0;
        int lf =max(0,maxPath(r->left,m));
        int rf =max(0,maxPath(r->right,m));
        m = max(m,lf+rf+r->val);
        return r->val+max(lf,rf);
    }
    int maxPathSum(TreeNode* r) {
        
        int max=INT_MIN;
        if( r==nullptr )return 0;
        maxPath( r,max );
        return max;
    }
};