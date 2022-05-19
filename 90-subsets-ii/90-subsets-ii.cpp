class Solution {
public:
    void subs( vector<int>&arr,vector<int>&dp,vector<vector<int>>&s,int index){
        
        s.push_back(dp);
        for( int i = index;i<arr.size();i++){
            if(i != index && arr[i] == arr[i-1])continue;
            else{
                dp.push_back( arr[i] );
                subs( arr,dp,s,i+1);
                dp.pop_back();
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>s;
        vector<int>dp;
        sort( nums.begin(),nums.end());
         subs( nums,dp,s,0);
        return s;
    }
};