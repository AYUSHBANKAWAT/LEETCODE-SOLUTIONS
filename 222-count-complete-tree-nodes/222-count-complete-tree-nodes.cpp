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
    int leftNode( TreeNode* root ){
        int left=0;
        while( root!=nullptr ){
            root=root->left;
            left++;
        }
        return left;
    }
    int rightNode( TreeNode* root ){
        int left=0;
        while( root!=nullptr ){
            root=root->right;
            left++;
        }
        return left;
    }
    int countNodes(TreeNode* root) {
        if(!root)return 0;
        int left = leftNode(root);
        int right = rightNode(root);
        if( left==right )return (1<<left)-1;
        else return 1+countNodes(root->left)+countNodes(root->right);
    }
};