class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>mpp(256,-1);
        //256 possible characters for a string
        int left = 0;
        int right = 0;
        int len = 0;
        while( right<s.size()){
            if( mpp[s[right]]!=-1)left =  max( mpp[s[right]]+1,left);
            mpp[s[right]]=right;
            len = max( len,right-left+1);
            right++;
        }
        return len;
    }
};