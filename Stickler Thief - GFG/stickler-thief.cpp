//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
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
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends