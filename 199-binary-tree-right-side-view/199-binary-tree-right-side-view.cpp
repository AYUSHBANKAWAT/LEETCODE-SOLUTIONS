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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if( root==nullptr )return ans;
        queue<pair<TreeNode*,int>>q;
        map<int,int>mp;
        q.push( {root,0} );
        while(!q.empty() ){
            auto t =q.front();
            q.pop();
            int k =t.second;
            TreeNode* node=t.first;
            mp[k]=node->val;
            if( node->left )q.push({node->left,k+1});
            if( node->right )q.push({node->right,k+1});
        }
        
        for( auto t : mp ){
            ans.push_back(t.second);
        }
        return ans;
        
    }
};