class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s1=strs[0];
        
        int i=1;
        int n = strs.size();
        //if( n==1 )return s1;
        while( i<n ){
            int t=0;
            while( t<s1.size() && t<strs[i].size() && s1[t]==strs[i][t] )t++;
            s1=s1.substr(0,t);
            i++;
        }
        return s1;
    }
};