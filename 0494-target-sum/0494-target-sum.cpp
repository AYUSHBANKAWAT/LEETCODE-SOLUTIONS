class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int sum = accumulate( nums.begin(),nums.end(),0);
        int s2 = (sum-target)/2;
        int n  = nums.size();
         if(sum-target < 0 or (sum-target)%2) return 0;
        
        vector<vector<int>>dp(n+1,vector<int>(s2+1,0));
        if(nums[0]==0) dp[0][0] = 2;
        else dp[0][0]=1;
        if(nums[0]!=0 and s2>=nums[0]) dp[0][nums[0]] =1;
        for( int i=1;i<n;i++ ){
            for( int j=0;j<=s2;j++ ){
                if(j>=nums[i]){
                    dp[i][j]=dp[i-1][j-nums[i]]+dp[i-1][j];
                }
                else dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n-1][s2];
        
    }
};