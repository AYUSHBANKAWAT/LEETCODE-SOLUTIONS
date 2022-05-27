class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
      int low=0;
      int high = nums.size()-2;
        while( low<=high ){
            int mid = (low+high)>>1;//right shift of 2
            if( nums[mid]==nums[mid^1] ){ //xor is used such that 100^1->101 & 101^1=100
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return nums[low];
    }
};