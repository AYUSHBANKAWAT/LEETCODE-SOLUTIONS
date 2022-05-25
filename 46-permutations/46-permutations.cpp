class Solution {
public:
    void permutate(vector<int>&arr,vector<vector<int>>&ans,int index){
        
        if( index == arr.size()){
            ans.push_back(arr);
            return;
        }
        
        for( int i=index;i<arr.size();i++){
            swap(arr[index],arr[i]);
            permutate(arr,ans,index+1);
            swap(arr[index],arr[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        permutate(nums,ans,0);
        return ans;
    }
};