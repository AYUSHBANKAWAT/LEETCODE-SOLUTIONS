//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
public:
    string removeSpecialCharacter(string s) {
        int n=s.size();
        for( int i=0;s[i]!='\0';i++ ){
            char ch = s[i];
            if( (ch>='a' and ch<='z' ) || (ch>='A' and ch<='Z' ))continue;
            else {
                s[i]=NULL;
                n--;
               // i=i==0?0:i-1;
                
            }
            
        }
       // cout<<s.size();
        if(n==0)s="-1";
        return s;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Solution ob;
        cout << ob.removeSpecialCharacter(s) << "\n";
    }

    return 0;
}
// } Driver Code Ends