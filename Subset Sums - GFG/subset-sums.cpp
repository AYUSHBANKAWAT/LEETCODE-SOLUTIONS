// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
void getData( vector<int>data,int N,int i,int sum,vector<int>&da){
    if( i==N ){
        da.push_back(sum);
        return;
    }
    getData(data,N,i+1,sum+data[i],da);
    getData(data,N,i+1,sum,da);
}
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int>data;
        getData(arr,N,0,0,data);
        return data;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends