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
    int getHieght(TreeNode*root){
        if( root==nullptr )return 0;
        int l = getHieght(root->left);
        int r = getHieght(root->right);
        return max(l,r)+1;
    }
    int diameterOfBinaryTre(TreeNode* root,int &t){
        //static int max=1;
        if( root==nullptr )return 0;
         int left = getHieght(root->left);
        int right = getHieght(root->right);
        t=t>(right+left)?t:right+left;
        diameterOfBinaryTre(root->left,t);
        diameterOfBinaryTre(root->right,t);
        return t;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int max=0;
        diameterOfBinaryTre(root,max);
        return max;
    }
};