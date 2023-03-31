//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int f( int price[],int i,int n,vector<vector<int>>&dp ){
        if( i==0 ){
           return n*price[0];
        }
        if( dp[i][n]!=-1 )return dp[i][n];
        int not_taken = 0+f( price,i-1,n,dp );
        int taken = INT_MIN;
        if( n>=i+1 ){
            taken = f( price,i,n-(i+1),dp )+price[i];
        }
        return dp[i][n] = max( taken,not_taken );
    }
    int cutRod(int price[], int n) {
        int sum=0;
        // for( int i=0;i<n;i++ ){
        //     sum+=price[i];
        // }
        vector<vector<int>>dp( n+1,vector<int>(n+1,-1));
        return f(price,n-1,n,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends