class Solution {
public:
    bool checkIfPangram(string s) {
        sort(s.begin(),s.end());
        if( s[0]!='a')return false;
        int cnt=1;
        for(int i=1;i<s.length();i++){
            if( s[i]-s[i-1]<=1 ){
                if( s[i]!=s[i-1] )cnt++;
            }
            else return false;
        }
        return cnt==26?true:false;
    }
};