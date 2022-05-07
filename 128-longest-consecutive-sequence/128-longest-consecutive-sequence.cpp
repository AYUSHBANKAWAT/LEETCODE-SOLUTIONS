class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int len=1;
        int maxlen=1;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]) continue;
            else if(nums[i+1]-nums[i]==1) len++;
            else {
                maxlen=max(len,maxlen);
                len=1;
            }
        }
        maxlen=max(len,maxlen);
        return maxlen;
    }
};