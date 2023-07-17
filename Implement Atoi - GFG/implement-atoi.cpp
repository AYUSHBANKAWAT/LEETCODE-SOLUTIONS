//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
         int k=0;
         int nev = 1;
         for( int i=0;i<str.size();i++ ){
             if( str[i]>='0' and str[i]<='9' ){
                 int kt = str[i]-'0'; // o --> 56 1-->57
                 k=k*10+kt;
             }else if( str[i]=='-' ){
               if( nev==-1 or k!=0 )return -1;
                nev=-1; 
             }
             else{
                 return -1;
             }
         }
         return nev*k;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends