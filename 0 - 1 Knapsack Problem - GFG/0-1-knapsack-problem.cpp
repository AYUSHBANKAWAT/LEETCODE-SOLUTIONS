//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int f( int W,int wt[],int val[],int n,vector<vector<int>>&dp ){
       if(n<0)return 0;
       if( dp[n][W]!=-1 )return dp[n][W];
       int not_pick = f( W,wt,val,n-1,dp );
       int pick=0;
       if( wt[n]<=W ){
           pick = f( W-wt[n],wt,val,n-1,dp )+val[n];
       }
       return dp[n][W]=max( pick,not_pick );
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       vector<vector<int>>dp(n,vector<int>(W+1,-1));
       return f(W,wt,val,n-1,dp);
       
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends