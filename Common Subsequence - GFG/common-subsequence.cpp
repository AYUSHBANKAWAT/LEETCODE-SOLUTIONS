//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	bool commonSubseq (string a, string b)
	{
	    sort(a.begin(),a.end());
	    sort(b.begin(),b.end());
	   // cout<<a<<endl;
	   // cout<<b<<endl;
	    for( int i=0,j=0;i<a.size() and j<b.size();){
	        if( a[i]==b[j] )return true;
	        else if( a[i]>b[j] )j++;
	        else {
	            i++;
	        }
	    }
	    return false;
	}
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--) 
	{
		string a, b; cin >> a >> b;
		Solution ob;
		cout << ob.commonSubseq (a, b) << '\n';
	}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends