//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for c++
class Solution {
  public:
    string removeChars(string s1, string s2) {
        // code here
        map<char,char>mp;
        for( int i=0;i<s1.size();i++ ){
            mp[s1[i]]=s1[i];
        }
        for( int j=0;j<s2.size();j++ ){
            mp[s2[j]]=NULL;
        }
        for( int i=0;i<s1.size();i++ ){
            s1[i]=mp[s1[i]];
        }
        return s1;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string string1,string2;
        cin >> string1; 
        cin >> string2;
        Solution ob;
        cout << ob.removeChars(string1,string2) << endl;
    }
    return 0;
}

// } Driver Code Ends