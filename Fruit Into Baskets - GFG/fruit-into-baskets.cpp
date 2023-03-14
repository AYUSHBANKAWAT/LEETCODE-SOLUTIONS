//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int totalFruits(int N, vector<int> &f) {
        vector<int>b( 2,0 );
        int type1=-1;
        int type2=-1;
        int ans=0;
        for( int i=0;i<N;i++ ){
            if( type1==-1 || type1==f[i] ){
                type1=f[i];
                b[0]++;
            }else if( type2==-1 || type2==f[i] ){
                type2=f[i];
                b[1]++;
            }else{
                ans = max( ans,b[0]+b[1] );
                int pre = i-1;
                while( pre>=0 and f[pre]==f[i-1] )pre--;
                type1 = f[i-1];
                b[0]=i-pre-1;
                type2=f[i];
                b[1]=1;
            }
            
        }
        ans = max(ans,b[0]+b[1]);
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> fruits(N);
        for (int i = 0; i < N; i++) cin >> fruits[i];
        Solution obj;
        cout << obj.totalFruits(N, fruits) << endl;
    }
    return 0;
}

// } Driver Code Ends