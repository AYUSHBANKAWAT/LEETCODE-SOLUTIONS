//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int mod =  pow(10,9)+7;
    int cnt=0;
    int f( vector<int>&a,int i,int target,vector<vector<int>>&dp ){
        if(i == 0){
            if(target==0 && a[0]==0)
                return 2;
            if(target==0 || target == a[0])
                return 1;
            return 0;
        }
        if( dp[i][target]!=-1 ){
            return dp[i][target];
        }
        int not_taken = f(a,i-1,target,dp);
        int taken = 0;
        if( a[i]<=target )taken = f( a,i-1,target-a[i],dp );
        
        return dp[i][target] = (not_taken + taken)%mod;
    }
  
    int countPartitions(int n, int d, vector<int>& arr) {
        int sum = accumulate(arr.begin(),arr.end(),0);
         if(sum-d<0) return 0;
    if((sum-d)%2==1) return 0;
        int s1 =(sum-d)/2;
        cnt=0;
        vector<vector<int>>dp( n,vector<int>(s1+1,-1) );
        return f( arr,n-1,s1,dp );
         
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends