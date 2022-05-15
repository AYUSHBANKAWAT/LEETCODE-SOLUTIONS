// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    static bool cmp( Item i1,Item i2 ){
        return (  ( (double) i1.value/i1.weight)>( (double) i2.value/i2.weight) );
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort( arr,arr+n,cmp);
        int c =0;
        double final=0.0;
        for( int i=0;i<n;i++){
            if( c+arr[i].weight<=W){
                c+=arr[i].weight;
                final+=arr[i].value;
            }
            else{
                double left = W - c; 
                final += (arr[i].value/(double)arr[i].weight)*(double)left;
                break;
            }
        }
        return final;
        
        
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends