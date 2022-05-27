// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void solve( vector<vector<int>>&m,vector<vector<bool>>&b,vector<string>&ans,int row,int col,int n,string s){
        if( row ==n-1 && col == n-1 ){
            ans.push_back(s);
            return;
        }
        //down
        if( row+1<n && !b[row+1][col] && m[row+1][col]==1 ){
            b[row][col]=true;
            solve( m,b,ans,row+1,col,n,s+'D');
            b[row][col]=false;
        }
        //left
        if( col-1>=0 && !b[row][col-1] && m[row][col-1]==1 ){
            b[row][col]=true;
            solve( m,b,ans,row,col-1,n,s+'L');
            b[row][col]=false;
        }
        
        //right
        if( col+1<n && !b[row][col+1] && m[row][col+1]==1 ){
            b[row][col]=true;
            solve( m,b,ans,row,col+1,n,s+'R');
            b[row][col]=false;
        }
        //up
        if( row-1>=0 && !b[row-1][col] && m[row-1][col]==1 ){
            b[row][col]=true;
            solve( m,b,ans,row-1,col,n,s+'U');
            b[row][col]=false;
        }
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<vector<bool>>board(n,vector<bool>(n,false));
        vector<string> ans;
        string s;
        if( m[0][0]==0)return ans;
        solve( m,board,ans,0,0,n,s);
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends