class Solution {
public:
    
    int getSum(vector<int>a){
        int sum=0;
        for( auto k:a ){
            sum+=k;
        }
        return sum;
    }
    bool subsetSum( vector<int>a,int B ){
        int N = a.size();
        vector<vector<bool>>grid(N+1,vector<bool>(B+1));
        for(int i = 0;i<N+1;i++)
        {
            for(int j = 0;j<B+1;j++)
            {
                if(i == 0)
                {
                    grid[i][j] = false;
                }
                if(j == 0)
                {
                    grid[i][j] = true;
                }
            }
        }
        for( int i=1;i<N+1;i++ ){
            for( int j=1;j<B+1;j++ ){
                if( a[i-1]<=j ){
                    grid[i][j]=grid[i-1][j-a[i-1]]||grid[i-1][j];
                }
                else grid[i][j]=grid[i-1][j];
            }
        }
        return grid[N][B];
    }
    bool canPartition(vector<int>& nums) {
        int sum = getSum(nums);
        if( sum%2!=0 )return false;
        return subsetSum(nums,sum/2);
        
    }
};