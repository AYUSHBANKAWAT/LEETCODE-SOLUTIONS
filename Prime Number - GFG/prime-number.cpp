//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int isPrime(int N){
        // code here
        if( N==0 or N==1 )return false;
        if( N==2 )return true;
        if( N%2==0 )return false;
        for( int i=2;i<=sqrt(N);i++ ){
            if( N%i==0 )return false;
        }
        return true;
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.isPrime(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends