class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        int sign = 1,t=0;
        long long ans = 0;    
        int j = 0;    
        while(j<n and s[j] == ' ') j++;    
        if(s[j] == '-'){
            sign = -1;
            j++;
        }     
        else if(s[j] == '+')    j++;         
        for(int i=j;i<n;i++){
           int p=s[i]-'0';        
            if(p>=0 && p<=9){           
                ans=ans*10+(p);
                if((ans>INT_MAX) && sign==-1) return INT_MIN;
                else if(ans >INT_MAX) return INT_MAX;       
            }
            else return ans*sign;
        }
        return (ans*sign);

    }
    
};