class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for( int i=0;i<n;i++){
            for( int j = i+1;j<n;j++){
                int sum_1 = nums[i]+nums[j];
                int sum_2 = target - sum_1;
                int left = j+1;
                int right = n-1;
                while(left<right){
                    int sum = nums[left]+nums[right];
                    if( sum<sum_2 ){
                        left++;
                    }else if( sum>sum_2 ){
                        right--;
                    }else{
                        vector<int>temp(4,0);
                        temp[0]=nums[i];
                        temp[1]=nums[j];
                        temp[2]=nums[left];
                        temp[3]=nums[right];
                        ans.push_back(temp);
                        
                        while(left<right && nums[left]==temp[2])++left;
                        while(left<right && nums[right]==temp[3])--right; 
                    }
                }
                while( j+1<n && nums[j]==nums[j+1] )++j;
            }
            while( i+1<n && nums[i]==nums[i+1] )++i;
        }
        return ans;
    }
};