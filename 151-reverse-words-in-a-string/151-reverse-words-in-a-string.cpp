class Solution {
public:
    string reverseWords(string s) {
        int i=0;
        int j=0;
        stack<string>st;
        string ans="";
       
        while( i<s.length() ){
           // while( s[i]==' ' && i<s.length() )i++;
            j=i+1;
            while( s[i]!=' ' && s[j] !=' '  && j<s.size())j++;
            if( s[i]!=' ')
            st.push(s.substr(i,j-i));
            i=j; 
        }
        
        while( !st.empty()){
            cout<<st.top()<<",";
           if( ans.empty() )ans=st.top();
           else {
               ans = ans+" "+st.top();
           }
            st.pop();
        }
        return ans;
    }
};