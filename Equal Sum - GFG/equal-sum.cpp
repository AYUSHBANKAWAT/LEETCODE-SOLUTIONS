//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string equilibrium(int *arr, int n) {
        // code here
        string yes = "YES";
        string no = "NO";
        int sum =0; 
        for(int i=0;i<n;i++)sum+=arr[i];
        int sum_lr=0;
        for( int i=0;i<n;i++ ){
            sum=sum-arr[i];
            if( sum_lr==sum )return yes;
            sum_lr+=arr[i];
        }
        return no;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.equilibrium(a, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends