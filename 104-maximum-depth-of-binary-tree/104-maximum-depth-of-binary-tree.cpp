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
    void maxDep( TreeNode*r,int &h,int &max ){
        if( r->right==nullptr and r->left==nullptr ){
            max = max>h?max:h;
            return;
        }
        if( r->left ){
            int k =h+1;
            maxDep(r->left,k,max);
        }
        if(r->right){
            int k =h+1;
            maxDep(r->right,k,max);
        }
    }
    int maxDepth(TreeNode* root) {
        int h=1;
        int max = 1;
        if( root==nullptr )return 0;
        maxDep(root,h,max);
        return max;
    }
};