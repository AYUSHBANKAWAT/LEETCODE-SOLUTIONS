//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution{
    public:
    
    bool f( string & s,string & p,int i,int j, vector<vector<int>>&dp ){
        if( i==0 and j==0 )return true;
        if( i==0 and j>0 ){
            for( int k = 1;k<=j;k++ )if( p[k-1]!='*' )return false;
            return true;
        }
        if( j==0 and i>0 )return false;
        if( dp[i][j]!=-1 )return dp[i][j];
        if(s[i-1]==p[j-1] or p[j-1]=='?' )return  dp[i][j] = f( s,p,i-1,j-1,dp );
        else if( p[j-1]=='*' ){
            return dp[i][j]= f( s,p,i-1,j,dp ) or f( s,p,i,j-1,dp );
        }
        return dp[i][j]= false;

    }
    
    bool match(string p, string s)
    {
       vector<vector<int>>dp( s.size()+1,vector<int>(p.size()+1,-1));
        return f( s,p,s.size(),p.size(),dp );
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        bool x=ob.match(wild, pattern);
        if(x)
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}
// } Driver Code Ends