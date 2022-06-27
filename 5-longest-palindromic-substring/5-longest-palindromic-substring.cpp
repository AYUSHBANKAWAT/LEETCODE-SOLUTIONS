class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        //cout<<n<<endl;
        if(n==1)return s;
        if(n==2){
            if(s[0]==s[1])return s;
           
        }
        int start=0;
        int len =1;
        string ans =""; 
        vector<vector<bool>>dp(s.length(),vector<bool>(s.length(),false));
        for( int g=0; g<n;g++){
            for( int i=0,j=g;j<n;i++,j++){
                if(g==0){
                    dp[i][j]=true;
                }
                else if( g==1 and s[i]==s[j] ){
                    dp[i][j]=true;
                    len=2;
                    start=i;
                }
                else{
                    if( s[i]==s[j] and dp[i+1][j-1] ){
                        dp[i][j]=dp[i+1][j-1];  
                        start=i;
                        len=j-i+1;
                }
                }
                
            }
        }
        
        return s.substr(start,len);
    }
};