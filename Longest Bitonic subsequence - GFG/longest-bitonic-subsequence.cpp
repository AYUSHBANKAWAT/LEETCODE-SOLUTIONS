//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
	    int n = nums.size();
	    vector<int>dp( n,1 );
	    int ls=0;
	    int maxi=0;
	    for( int i=0;i<n;i++ ){
	        for( int prev=0;prev<i;prev++ ){
	            if( nums[prev]<nums[i] and dp[prev]+1>dp[i] ){
	                dp[i]=dp[prev]+1;
	            }
	        }
	        if(maxi<dp[i]){
	            maxi= dp[i];
	            ls=i;
	        }
	    }
	    int maxi2=0;
	    vector<int>dp2( n,1 );
	    for( int i=n-1;i>=0;i-- ){
	        for( int prev=n-1;prev>=i;prev-- ){
	            if( nums[prev]<nums[i] and dp2[prev]+1>dp2[i] ){
	                dp2[i]=dp2[prev]+1;
	            }
	        }
	        if(maxi2<dp2[i]){
	            maxi2= dp2[i];
	        }
	    }
	    int maxed=0;
	    for( int i=0;i<n;i++ ){
	        maxed = max( maxed, dp[i]+dp2[i]-1);
	    }
	    return maxed;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends