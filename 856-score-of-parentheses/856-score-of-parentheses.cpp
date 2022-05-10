class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int>st;
        for( auto c:s ){
            if( c=='(' ){
                st.push(-1);
            }else{
                if( st.top()==-1){
                    st.pop();
                    st.push(1);
                }else{
                    int sum =0;
                    while(st.top()!=-1){
                        sum+=st.top();
                        st.pop();
                    }
                    st.pop();
                    sum = 2*sum;
                    st.push(sum);
                }
            }
        }
        if(st.size()!=1){
            int sum =0;
            while( !st.empty()){
                sum+=st.top();
                st.pop();
            }
            return sum;
        }
        return st.top();
        
    }
};