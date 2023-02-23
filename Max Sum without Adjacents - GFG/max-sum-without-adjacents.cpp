//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
    int f( int i,int * a,vector<int>&dp ){
        if( i==0 )return a[0];
        if( i<0 )return 0;
        if( dp[i]!=-1 )return dp[i];
        int pick = a[i]+f( i-2,a,dp );
        int not_pick = f( i-1,a,dp );
        return dp[i] = max(pick,not_pick  );
    }
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    vector<int>dp(n,-1);
	    return f(n-1,arr,dp);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends