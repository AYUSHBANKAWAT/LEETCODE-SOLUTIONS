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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if( inorder.size()!=postorder.size() )return nullptr;
        map<int,int>mp;
        for( int i=0;i<postorder.size();i++ ){
            mp[inorder[i]]=i;
        }
        return generateTree( inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,mp);
    }
    TreeNode* generateTree( vector<int>inorder,int inStart,int inEnd,vector<int>postorder,int poStart,int poEnd,map<int,int>&mp ){
        if( inStart>inEnd or poStart>poEnd )return nullptr;
        TreeNode*r = new TreeNode(postorder[poEnd]);
        int inroot = mp[postorder[poEnd]];
        int numLeft = inroot-inStart;
        r->left = generateTree( inorder,inStart,inroot-1,postorder,poStart,poStart+numLeft-1,mp);
        r->right = generateTree( inorder,inroot+1,inEnd,postorder,poStart+numLeft,poEnd-1,mp);
        return r;
    }
};