//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    int curr_max,pre_max,curr_i,pre_i;
	    if( arr[n-1]>arr[n-2] ){
	        curr_max =arr[n-1];
	        curr_i=n-1;
	        pre_max=arr[n-2];
	        pre_i=n-2;
	    }
	    else{
	        curr_max =arr[n-2];
	        curr_i=n-2;
	        pre_max=arr[n-1];
	        pre_i=n-1;
	    }
	    for( int i = n-3;i>=0;i-- ){
	        if( curr_i-i==1 ){
	           int pos_max = pre_max+arr[i];
	           //int pos_i = i;
	           if( pos_max>=curr_max ){
	               pre_max = curr_max;
	               pre_i = curr_i;
	               curr_max = pos_max;
	               curr_i = i;
	           }else{
	               pre_max = pos_max;
	               pre_i = i;
	           }
	        }else{
	            int pos_max = curr_max+arr[i];
	            pre_max = curr_max;
	            pre_i = curr_i;
	            curr_max = pos_max;
	            curr_i = i;
	        }
	        //cout<<curr_max<<"  "<<pre_max<<endl;
	    }
	    return max( curr_max,pre_max );
	    
	    
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