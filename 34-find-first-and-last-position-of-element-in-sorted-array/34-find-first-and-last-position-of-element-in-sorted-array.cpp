class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int index=-1;
        for( int i=0;i<nums.size();i++ ){
            if(nums[i]==target){
                index=i;
                break;
            }
        }
        if(index!=-1){
            int index2=-1;
            for(int j=index;j<nums.size();j++){
                if(nums[j]==target){
                index2=j;
               }
            }
            
            vector<int>ans = {index,index2};
            return ans;
        }
        vector<int>ans = {-1,-1};
            return ans;
    }
};