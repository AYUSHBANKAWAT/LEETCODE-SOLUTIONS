class Solution {
public:
    int mySqrt(int x) {
         long low =  1;
         long high = x;
        if(x==0)return 0;
        while( high-low>1){
           long long mid = (high+low)/2;
            if( mid*mid<=x)low=mid;
            else high=mid;
        }
        return low;
        
    }
};