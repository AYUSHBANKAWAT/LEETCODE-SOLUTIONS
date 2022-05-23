class Solution {
public:
    void cs(vector<int>& arr,vector<int>&dp,vector<vector<int>>&ans,int target,int index){
       // if( target<0  || index>=arr.size())return;
        if( target == 0 ){
            ans.push_back(dp);
            return;
        }
        for( int i = index;i<arr.size();i++){
            if( i>index && arr[i]==arr[i-1])continue;
            if(arr[i]>target)break;
            
                dp.push_back(arr[i]);
                cs(arr,dp,ans,target-arr[i],i+1);
                dp.pop_back();
            
        }
      //  cs(arr,dp,ans,target,index+1);
        
        
    }
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        vector<vector<int>>ans;
        vector<int>dp;
        sort(arr.begin(),arr.end());
        cs(arr,dp,ans,target,0);
        return ans;
    }
};