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
        int i=0;
        return bst(preorder,i,INT_MAX);
    }
    TreeNode* bst( vector<int>A,int &i,int bound ){
        if( i==A.size() or A[i]>bound )return NULL;
        TreeNode * t = new TreeNode(A[i++]);
        t->left = bst(A,i,t->val);
        t->right= bst(A,i,bound );
        return t;
    }
};