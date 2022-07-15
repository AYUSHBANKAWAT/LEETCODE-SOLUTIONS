class Solution {
public:
    long double facto(int n){
        if(n==0 || n==1)return 1;
        if(n<0)return 0;
        return n*facto(n-1);
    }
    int numTrees(int n) {
        //cout<<facto(n)<<endl;
        int t= ceil(facto(2*n)/(facto(n+1)*facto(n)));
        return t;
    }
};