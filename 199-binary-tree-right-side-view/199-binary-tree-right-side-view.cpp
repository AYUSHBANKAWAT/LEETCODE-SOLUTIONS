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
    void solve( TreeNode*r,vector<int>&t,int level ){
        if( r==nullptr )return;
        if( level==t.size() )t.push_back(r->val);
        solve( r->right,t,level+1 );
        solve(r->left,t,level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        
       vector<int>ans; 
       solve(root,ans,0);
        return ans;
    }
};