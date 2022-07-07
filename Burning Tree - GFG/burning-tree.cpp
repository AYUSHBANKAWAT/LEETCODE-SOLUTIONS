// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  Node* getParent(Node* root,unordered_map<Node*,Node*>&mp,int k,int & nodes){
      queue<Node*>q;
      q.push(root);
      Node*temp=nullptr;
      while(!q.empty()){
          nodes++;
           auto t =q.front();
           if(t->data==k)temp=t;
           q.pop();
           if(t->left){
               mp[t->left]=t;
               q.push(t->left);
           }
           if( t->right ){
               mp[t->right]=t;
               q.push(t->right);
           }
      }
      return temp;
  }
    int minTime(Node* root, int target) 
    {
        unordered_map<Node*,Node*>mp;
        int nodes=0;
        Node*kn  = getParent(root,mp,target,nodes);
        queue<Node*>q;
        unordered_map<Node*,bool>visited;
        q.push(kn);
        int time_taken=0;
        int burnedNodes=0;
        while( !q.empty() ){
            int size=q.size();
            time_taken++;
           // if( burnedNodes == nodes )break;
            for( int i=0;i<size;i++ ){
                auto t = q.front();
                q.pop();
                if( t->left and !visited[t->left] ){
                    q.push(t->left);
                    visited[t->left]=true;
                }
                if( t->right and !visited[t->right] ){
                    q.push(t->right);
                    visited[t->right]=true;
                }
                if( mp[t] and !visited[mp[t]] ){
                    q.push(mp[t]);
                    visited[mp[t]]=true;
                }
            }
        }
        return time_taken-1;
    }
};

// { Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}
  // } Driver Code Ends