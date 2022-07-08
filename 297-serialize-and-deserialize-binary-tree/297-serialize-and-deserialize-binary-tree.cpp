/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if( !root )return "";
        queue<TreeNode*>q;
        q.push(root);
        string s="";
        while(!q.empty()){
            auto t = q.front();
            q.pop();
            if( !t )s.append("#,");
            else{
                s.append(to_string(t->val)+',');    
                q.push(t->left);
                q.push(t->right);
            }
        }
        //cout<<s;
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if( data.size()==0 )return nullptr;
        stringstream s(data);
        string str;
        getline(s,str,',');
        
        queue<TreeNode*>q;
        TreeNode* y = new TreeNode(stoi(str));
        q.push(y);
       // cout<<q.size();
        while( !q.empty() ){
            auto t = q.front();
            q.pop();
            getline(s,str,',');
            if( str=="#" ){
                t->left=nullptr;
            }else{
                t->left = new TreeNode(stoi(str));
                q.push(t->left);
            }
            getline(s,str,',');
            if( str=="#" ){
                t->right=nullptr;
            }else{
                t->right = new TreeNode(stoi(str));
                q.push(t->right);
            }
        }
        return y;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));