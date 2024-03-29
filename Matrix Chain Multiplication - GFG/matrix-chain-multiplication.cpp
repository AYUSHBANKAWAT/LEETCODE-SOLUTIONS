//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>>dp( N,vector<int>(N,-1) );
        for( int i=0;i<N;i++ ){
            dp[i][i]=0;
        }
        for( int i=N-1;i>0;i-- ){
            for( int j =i+1;j<N;j++ ){
                int kt  = INT_MAX;
                for( int k = i;k<j;k++ ){
                    int d= arr[i-1]*arr[k]*arr[j]+dp[i][k]+dp[k+1][j];
                    kt = min( kt,d );
                }
                dp[i][j] = kt;
            }
        }
        // for( int i=0;i<N;i++ ){
        //     for( int j=0;j<N;j++ ){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return dp[1][N-1];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends