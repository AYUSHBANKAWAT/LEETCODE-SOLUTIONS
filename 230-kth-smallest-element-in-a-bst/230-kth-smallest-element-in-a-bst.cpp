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
    int kthSmallest(TreeNode* r, int k) {
        vector<int>ans;
        while( r ){
            if( !r->left ){
                ans.push_back(r->val);
                r=r->right;
            }
            else{
                TreeNode*t = r->left;
                while( t->right and t->right!=r )t=t->right;
                if( t->right==nullptr ){
                    t->right=r;
                    r=r->left;
                }else{
                    ans.push_back(r->val);
                    t->right=nullptr;
                    r=r->right;
                }
            }
        }
        for( auto a:ans )cout<<a<<" ";
        cout<<endl;
        return ans[k-1];
    }
};