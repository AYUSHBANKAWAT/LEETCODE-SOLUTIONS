class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
    vector<int>ans(n);
    stack<int>s;
    k++;
    for( int i=n-1;i>=0;i-- ){
        while( !s.empty() && nums[i]>=nums[s.top()] )s.pop();
        if( s.empty() )ans[i]=nums.size();
        else {
           ans[i]=s.top();
        }
        s.push(i);
    }
    vector<int>st(n);
    int j =0;
    for( int i =0;i<=n-k+1;i++){
    // Enter the loop to get the largest in the window starting at i
    if( j<i )j=i;
    //int j = i;
    while(ans[j]<i+k-1)j=ans[j];
    ans[i]=nums[j];
    }
    ans.resize(n-k+2);
    return ans;
    }
};