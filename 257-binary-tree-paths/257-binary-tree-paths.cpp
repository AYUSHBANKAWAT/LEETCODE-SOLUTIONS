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
    void getPaths( vector<string>&a,string &s,TreeNode* root ){
        if( root==nullptr )return;
        //char c = root->val+'0';
        if( !root->left and !root->right ){
            string h=to_string(root->val);
            s+=h;
            a.push_back(s);
            s.resize(s.size()-h.size());
            return;
        }
        string k = to_string(root->val)+"->";
        s+=k;
        getPaths(a,s,root->left);
        getPaths(a,s,root->right);
        s.resize(s.size()-k.size());
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        string s="";
        getPaths(ans,s,root);
        return ans;
    }
};