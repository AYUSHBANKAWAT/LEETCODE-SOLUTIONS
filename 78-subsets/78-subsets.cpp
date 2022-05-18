class Solution {
public:
    void subs( vector<vector<int>>&ans,vector<int>&dp,vector<int>&arr,int i){
        if( i==arr.size()){
            ans.push_back(dp);
            return;
        }
        subs( ans,dp,arr,i+1);
        dp.push_back(arr[i]);
        subs( ans,dp,arr,i+1);
        dp.pop_back();
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>a;
        subs(ans,a,nums,0);
        return ans;
    }
};