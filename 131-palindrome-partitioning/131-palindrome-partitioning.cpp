class Solution {
public:
    bool checkPalindrome(string s,int i,int j ){
        
        while( i<j){
            if( s[i]!=s[j] )return false;
            i++;j--;
        }
        return true; 
    }
    void fun(int ind,string s,vector<string>&p,vector<vector<string>>&res){
        if( ind == s.size() ){
            res.push_back(p);
            return;
        }
        for( int i=ind;i<s.size();i++){
            if( checkPalindrome(s,ind,i)){
                p.push_back(s.substr(ind,i-ind+1));
                fun( i+1,s,p,res );
                p.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>dp;
        vector<vector<string>>res;
        fun(0,s,dp,res);
        return res;
    }
};