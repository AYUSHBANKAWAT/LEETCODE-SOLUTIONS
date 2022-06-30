class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort( nums.begin(),nums.end() );
        int mid = nums.size()/2;
        int k=0;
        for( auto a:nums ){
            int t = a>nums[mid]?a-nums[mid]:nums[mid]-a;
            k+=t;
        }
        return k;
    }
};