//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int f( int * a, int i, int prev, vector<vector<int>>& dp,int n ){
        if( i>=n )return 0;
        if( dp[i][prev+1]!=-1 )return dp[i][prev+1]; 
        int not_taken = f( a,i+1,prev,dp,n );
        int taken = INT_MIN;
        if( prev==-1 or a[prev]<a[i] )taken = 1+ f( a,i+1,i,dp,n );
        return dp[i][prev+1] = max( not_taken,taken );
    }
    int longestSubsequence(int n, int a[])
    {
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
       int * p =a;
       return f( p,0,-1,dp,n );
       
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends