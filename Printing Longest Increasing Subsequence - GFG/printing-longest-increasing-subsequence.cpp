//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        vector<int>dp(n,1);
        vector<int>hash(n);
        int l_index = 0;
        int maxi  = 0;
        for( int i =0;i<n;i++ ){
            hash[i]=i;
            for( int prev = 0;prev<i;prev++ ){
                if( arr[prev]<arr[i] and dp[i]<dp[prev]+1 ){
                    dp[i]=dp[prev]+1;
                    hash[i]=prev;
                }
            }
            if( dp[i]>maxi ){
                maxi=dp[i];
                l_index=i;
            }
        }
        vector<int>lis;
        int ind=0;
        lis.push_back(arr[l_index]);
        while( hash[l_index] != l_index){
            l_index = hash[l_index];
            lis.push_back(arr[l_index]);
        }
        reverse( lis.begin(),lis.end() );
        return lis;
       
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
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends