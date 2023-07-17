//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        vector<int>lr(n,0);
        vector<int>rl(n,0);
        int maxi = arr[n-1];
        for( int i=n-1;i>=0;i-- ){
            maxi= maxi>arr[i]?maxi:arr[i];
            rl[i]=maxi-arr[i];
        }
        maxi = arr[0];
        for( int i=0;i<n;i++ ){
            maxi= maxi>arr[i]?maxi:arr[i];
            lr[i]=maxi-arr[i];
        }
        long long vol =0;
        for( int i=0;i<n;i++ ){
            vol+=min(rl[i],lr[i]);
        }
        return vol;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends