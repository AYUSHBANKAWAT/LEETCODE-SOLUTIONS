//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> v, long long n, long long x){
        
        // Your code here   x==5
        /*
        1 2  4 6 7 
        
        */
        
        int i=0;
        int j = n;
        if( n==1 ){
            return v[0]>x?-1:v[0];
        }
        if( x<v[0] )return -1;
        if( x>=v[j-1] )return j-1;
        int mid=0;
        int index=-1;
        int min_diff=INT_MAX;
        while( i<=j ){
                mid =(i+j)/2;
                if( v[mid]>x )j=mid-1;
                else if( v[mid]<x ){
                    int k =  x-v[mid];
                    if( k<min_diff ){
                        index=mid;
                        min_diff=k;
                        i=mid+1;
                    }
                }
                else {
                    return mid;
                }
        }
        return index;
    }
};


//{ Driver Code Starts.

int main() {
	
	long long t;
	cin >> t;
	
	while(t--){
	    long long n;
	    cin >> n;
	    long long x;
	    cin >> x;
	    
	    vector<long long> v;
	    
	    for(long long i = 0;i<n;i++){
	        long long temp;
	        cin >> temp;
	        v.push_back(temp);
	    }
	    Solution obj;
	    cout << obj.findFloor(v, n, x) << endl;
	   
	}
	
	return 0;
}
// } Driver Code Ends