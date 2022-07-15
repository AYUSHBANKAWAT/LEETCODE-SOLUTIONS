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
    void getinorder(vector<int>&a,TreeNode*r){
        if( !r )return;
        getinorder(a,r->left);
        a.push_back(r->val);
        getinorder(a,r->right);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>data;
        getinorder(data,root);
        int i=0,j=data.size()-1;
        while(i<j){
            if( data[i]+data[j]==k )return true;
            else if( data[i]+data[j]>k )j--;
            else i++;
        }
        return false;
    }
};