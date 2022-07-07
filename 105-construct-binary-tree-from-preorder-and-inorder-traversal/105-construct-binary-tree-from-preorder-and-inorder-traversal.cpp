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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>mp;
        for( int i=0;i<inorder.size();i++ ){
            mp[inorder[i]]=i;
        }
       return  generateTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp); 
    }
    TreeNode* generateTree( vector<int>preorder,int preStart,int preEnd,vector<int>inorder,int inStart,int inEnd,map<int,int>&mp){
        if( preStart>preEnd or inStart>inEnd )return nullptr;
        TreeNode * root = new TreeNode(preorder[preStart]);
        int inroot = mp[root->val];
        int numLeft = inroot-inStart;
        root->left = generateTree(preorder,preStart+1,preStart+numLeft,inorder,inStart,inroot-1,mp);
        root->right =  generateTree(preorder,preStart+numLeft+1,preEnd,inorder,inroot+1,inEnd,mp);
        return root;
    }
};