//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int strstr(string ,string);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a;
        string b;
        
        cin>>a;
        cin>>b;
        
        cout<<strstr(a,b)<<endl;
    }
}

// } Driver Code Ends


//Function to locate the occurrence of the string x in the string s.
int strstr(string s, string x)
{
    int n =s.size();
     for( int i=0;i<n; ){
         if( s[i]==x[0] ){
             int ans =i;
             bool same = true;
             int o =i;
             for( int j=0;j<x.size() and i<n ;j++ ){
                 if(s[o]!=x[j]){
                     same=false;
                     break;
                 }
                 o++;
             }
             if( same )return ans;
             else i++;
         }
         else i++;
     }
     return -1;
}