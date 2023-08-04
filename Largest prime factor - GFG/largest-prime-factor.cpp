//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public: 
    
    bool isPrime( int n ){
        if( n<=1 )return false;
        if( n==2 )return true;
        for( int i=2;i<=sqrt(n);i++ ){
            if( n%i==0 )return false;
        }
        return true;
    }
    
    long long int largestPrimeFactor(int N){
        int maxi =0;
        for( int i=1;i<=sqrt(N);i++ ){
            if( N%i==0 ){
                if( isPrime(i) ){
                     maxi= max( i,maxi );
                }
                if(i!=N/i and isPrime(N/i) ){
                     maxi= max( N/i,maxi );
                }
            }
        }
        return maxi;
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
        cout << ob.largestPrimeFactor(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends