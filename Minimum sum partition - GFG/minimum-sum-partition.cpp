//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
   int minimumDifference(vector<int>& nums) {
        int n =  nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        vector<vector<bool>>dp(n+1,vector<bool>(sum+1));
        for( int i=0;i<=n;i++ ){
            for( int j=0;j<=sum;j++ ){
                if( i==0 )dp[i][j]=false;
                if(j==0)dp[i][j]=true;
            }
        }
        int mid = sum/2;
        for( int i=1;i<=n;i++ ){
            for( int j=1;j<=sum;j++ ){
                if( j>=nums[i-1] ){
                    dp[i][j]=dp[i-1][j-nums[i-1]]||dp[i-1][j];
                }
                else dp[i][j]=dp[i-1][j];
            }
        }
        vector<int>ans;
        for( int i=0;i<=mid;i++){
            if( dp[n][i] )ans.push_back(i);
        }
        int mn =INT_MAX;
        for( int i=0;i<ans.size();i++ ){
            mn = min(mn,sum-2*ans[i]);
        }
        return mn;
    }
  
	int minDifference(int numsArr[], int n)  { 
	   vector<int> nums;
   for (int i=0; i < n; i++) {
      nums.push_back(numsArr[i]);
   }
	   return minimumDifference(nums);
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends