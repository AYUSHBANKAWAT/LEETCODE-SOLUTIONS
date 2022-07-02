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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==nullptr)return 0;
        int ans=0;
        queue<pair<TreeNode*,long long int>>q;
        q.push({root,0});
        while( !q.empty() ){
            int size = q.size();
            int mmin = q.front().second;
            int first,last;
            for( int i=0;i<size;i++ ){
                int num  = q.front().second-mmin;
                auto t = q.front().first;
                q.pop();
                if( i==0 )first = num;
                if( i==size-1 )last = num;
                if( t->left ){
                    q.push( {t->left,1LL*2*num+1} );
                }
                if( t->right ){
                    q.push( {t->right,1LL*2*num+2} );
                }
            }
            ans = max(ans,last-first+1);
        }
        return ans;
    }
};