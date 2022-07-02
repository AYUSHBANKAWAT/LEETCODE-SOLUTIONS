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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if( root==nullptr )return ans;
        queue<TreeNode*>q;
        q.push(root);
        int k=1;
        bool leftToright=true;
        while( !q.empty() ){
            int size = q.size();
            vector<int>temp(size);
            for( int i=0;i<size;i++ ){
                int index = leftToright?i:size-1-i;
                auto d = q.front();
                q.pop();
                temp[index]=d->val;
                if( d->left )q.push(d->left);
                if( d->right )q.push(d->right);
            }
            leftToright=!leftToright;
            ans.push_back(temp);
            
        }
        return ans;
    }
};