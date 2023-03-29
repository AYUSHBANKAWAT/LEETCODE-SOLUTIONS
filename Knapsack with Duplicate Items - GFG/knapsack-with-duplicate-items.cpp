//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int f( int val[],int wt[],int N,int W,vector<vector<int>>&dp ){
        if(N == 0){
        return ((int)(W/wt[0])) * val[0];
        }
        if( dp[N][W]!=-1 ){
         return dp[N][W];   
        }
        int not_pick = 0+f(val,wt,N-1,W,dp);
        int pick=INT_MIN;
        if( W>=wt[N] ){
            pick = f( val,wt,N,W-wt[N],dp )+val[N];
        }
            return dp[N][W]=max(pick,not_pick);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>>dp( N,vector<int>(W+1,-1) );
        return f( val,wt,N-1,W,dp );
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends