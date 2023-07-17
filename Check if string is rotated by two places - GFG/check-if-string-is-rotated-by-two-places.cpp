//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string str1, string str2)
    {
        if( str1.size()!=str2.size() )return false;
        if( str1.size()==1 )return str1[0]==str2[0];
        string k1=str2;
        string k2 = str2;
        rotate(k1.begin(),k1.begin()+2,k1.end());
        int n =k2.size();
        rotate( k2.begin(),k2.begin()+n-2,k2.end() );
        return str1==k1 || str1==k2;
    }

};


//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		Solution obj;
		cout<<obj.isRotated(s,b)<<endl;
	}
	return 0;
}

// } Driver Code Ends