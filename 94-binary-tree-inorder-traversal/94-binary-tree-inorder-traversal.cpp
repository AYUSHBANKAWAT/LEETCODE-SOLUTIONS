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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        TreeNode* r = root;
        while( r ){
            if( !r->left ){
                ans.push_back(r->val);
                r=r->right;
            }
            else{
                TreeNode*pre = r->left;
                while( pre->right and pre->right!=r )pre=pre->right;
                if( pre->right==nullptr ){
                    pre->right=r;
                    r=r->left;
                }else{
                    ans.push_back(r->val);
                    pre->right=nullptr;
                    r=r->right;
                }
            }
        }
        return ans;
    }
};