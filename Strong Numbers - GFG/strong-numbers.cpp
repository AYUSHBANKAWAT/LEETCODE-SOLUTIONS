//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int facto( int i ){
        if(i==0)return 1;
        if( i==1 )return 1;
        return facto(i-1)*i;
    }
    int isStrong(int N) {
        int  k = N;
        long long sum =0;
        while( k>0 ){
            int m  = k%10;
            int kt=(int)facto(m);
            if(sum>N or kt+sum>N)return 0;
            sum=sum+kt;
            k=k/10;
        }
        return sum==N;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.isStrong(N) << endl;
    }
    return 0;
}
// } Driver Code Ends