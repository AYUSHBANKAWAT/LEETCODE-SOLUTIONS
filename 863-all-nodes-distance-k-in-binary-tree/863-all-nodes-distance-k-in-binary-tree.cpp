/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void getParents( TreeNode*root,unordered_map<TreeNode*,TreeNode*>& mp ){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
           // int size = q.size();
            auto c_node = q.front();
            q.pop();
            if( c_node->left ){
                mp[c_node->left]=c_node;
                q.push(c_node->left);
            }
            if(c_node->right){
                mp[c_node->right]=c_node;
                q.push(c_node->right);
            }
        }
        
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parent;
        getParents(root,parent);
        unordered_map<TreeNode*,bool>visited;
        queue<TreeNode*>q;
        visited[target]=true;
        q.push(target);
        int curr_level=0;
        while(!q.empty()){
            int size = q.size();
            if(curr_level++ == k)break;
            for( int i=0;i<size;i++ ){
                auto t = q.front();q.pop();
                if( t->left and !visited[t->left] ){
                    visited[t->left]=true;
                    q.push(t->left);
                }
                if( t->right and !visited[t->right] ){
                    visited[t->right]=true;
                    q.push(t->right);
                }
                if( parent[t] && !visited[parent[t]] ){
                    q.push(parent[t]);
                    visited[parent[t]]=true;
                }
            }
        }
        vector<int>ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
        
        
    }
};