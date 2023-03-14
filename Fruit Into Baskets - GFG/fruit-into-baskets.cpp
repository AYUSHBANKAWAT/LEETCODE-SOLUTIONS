//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    static bool cmp(pair<int, int>& a,pair<int, int>& b){
        return a.second > b.second;
    }     
    
    int totalFruits(int N, vector<int> &nums) {
        int k =nums[0];
        if(nums.size()==1)return 1;
        int i;
        map<int,int>mp;
        for(  i=0;i<nums.size();i++ ){
            mp[nums[i]]++;
            if( k!=nums[i] )break;
        }
        if( i>=nums.size() )return mp[nums[0]];
        int maxi=mp[nums[0]]+1;
        i++;
        //cout<<maxi<<endl;
        int p=0;
        int u=0;
        while(i<nums.size()){
           if( mp.find(nums[i])!=mp.end()){
               mp[nums[i]]++;
               if( mp.size()>=3 ){
                    mp[nums[p]]--;
                    if( mp[nums[p]]<=0 ){
                   mp.erase(nums[p]);
                   }
                   p++;
               }
           }
           else{
             //  cout<<"check";
               mp[nums[i]]++;
              // cout<<mp[nums[p]];
               mp[nums[p]]--;
              // cout<<mp[nums[p]]<<endl;
               if( mp[nums[p]]<=0 ){
                   mp.erase(nums[p]);
                   }
               p++;
              // cout<<" p"<<p<<endl;
           }
           int sum =0;
           int cnt=0;
          int fe=0;
          int me=0;
           for( auto itr = mp.begin();itr!=mp.end() ;++itr ){
               if( fe<itr->second ){
               sum=itr->second;
               fe=sum;
               me = itr->first;}
            }
            fe=0;
            int h=0;
            for( auto itr = mp.begin();itr!=mp.end() ;++itr ){
               if( me!=itr->first and  fe<itr->second ){
               h=itr->second;
               fe=h;}
               //me = itr->first;
           }
           sum=sum+h;
           maxi = sum>maxi?sum:maxi;
           i++;
       
        }
        return maxi;
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