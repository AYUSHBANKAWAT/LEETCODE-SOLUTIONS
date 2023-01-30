//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int fibo( vector<long long int>&a,long long int n ){
        int mod = 1000000007;
        if( a[n]!=-1 )return a[n];
        else {
            return a[n]= (fibo(a,n-1)+fibo(a,n-2))%mod;
        }
    }
    long long int nthFibonacci(long long int n){
      vector<long long int>dp(n+1,-1);
      dp[0]=0;
      dp[1]=1;
      fibo(dp,n);
    //   for( auto a : dp )cout<<a<<"  ";
    //   cout<<endl;
      return dp.back();
    }
    
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends