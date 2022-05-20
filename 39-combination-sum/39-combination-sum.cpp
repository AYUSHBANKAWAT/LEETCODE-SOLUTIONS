class Solution {
public:
    
    void cs( vector<int>&arr,set<vector<int>>&s,vector<int>&dp,int t,int sum,int index){
        if( index== arr.size()){
            if( t==sum )s.insert(dp);
            return;
        }
        if( sum == t ){
            s.insert(dp);
            return;
        }
        else if(sum>t)return;
        else{
            dp.push_back(arr[index]);
            cs( arr,s,dp,t,sum+arr[index],index);
            dp.pop_back();
            cs( arr,s,dp,t,sum,index+1);
            dp.push_back( arr[index] );
            cs( arr,s,dp,t,sum+arr[index],index+1);
            dp.pop_back();
            return;
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& st, int target) {
        set<vector<int>>s;
        vector<int>dp;
        sort(st.begin(),st.end());
        cs(st,s,dp,target,0,0);
        vector<vector<int>>as(s.begin(),s.end());
        return as;
    }
};