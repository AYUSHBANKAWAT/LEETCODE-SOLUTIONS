class Solution {
public:
    int scoreOfParentheses(string s) 
    {
        stack<int> st;
        
        for (char ch : s)
        {
            if (ch != ')')
            {
                st.push(-1);
            }
            else
            {
                int result = 0;
                
                while (!st.empty() and st.top() != -1)
                {
                    result += st.top();
                    
                    st.pop();
                }
                
                st.pop();
                
                if (result == 0)
                {
                    st.push(1);
                }
                else
                {
                    st.push(result * 2);
                }
            }
        }
        
        if (st.size() == 1)
        {
            return st.top();
        }
        else
        {
            int result = 0;
            
            while (!st.empty())
            {
                result += st.top();
                
                st.pop();
            }
            
            return result;
        }
    }
};