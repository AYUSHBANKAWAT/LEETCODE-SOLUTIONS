//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    int f( vector<int>&h,int n,vector<int>&dp ){
        if( n==0 )return 0;
        if( dp[n]!=-1 )return dp[n];
        int taken_one = f( h,n-1,dp )+abs( h[n] -h[n-1]);
        int taken_two = INT_MAX;
        if( n>=2 ) taken_two =  f( h,n-2,dp )+abs( h[n] -h[n-2]);
        
        return dp[n] = min( taken_one,taken_two );
        
    }
    int minimumEnergy(vector<int>& height, int n) {
        vector<int>dp( n+1,-1 );
        return f( height,n-1,dp );
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends