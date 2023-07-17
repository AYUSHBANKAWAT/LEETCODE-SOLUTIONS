//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string s) 
    { 
        string k="";
        string m="";
        int n =s.size();
        for( int i=0;i<n;i++ ){
            if( s[i]=='.' ){
                m=k+m;
                m="."+m;
                k="";
            }else{
                k+=s[i];
            }
        }
        m=k+m;
        return m;
        
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends