//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
      //  if( arr1[0]>arr2[0] )return kthElement(arr1,arr2,n,m,k);
        int i=0;
        int j=0;
        int k1=0;
       // k--;
       int ans =0;
        while( k1!=k and i<n and j<m ){
            if( arr1[i]<arr2[j] ){
                ans=arr1[i];
                i++;
                //ans=arr1[i];
            }
            else {
                ans=arr2[j];
                j++;
            }
            k1++;
        }
        while( k1!=k and i<n ){
            k1++;
            ans=arr1[i];
            i++;
        }
        while( k1!=k and j<m ){
            k1++;
            ans=arr2[j];
            j++;
        }
      //  cout<<i<<" "<<j<<endl;
        return ans;
    }
};

//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends