class Solution {
public:
    static bool cmp( vector<int>a,vector<int>b ){
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& b, int s) {
        //cout<<endl;
        sort(b.begin(),b.end(),cmp);
        int total=0;
        int i=0;
        while( i<b.size() and s!=0){
            while(b[i][0]!=0 and s!=0 ){
                total+=b[i][1];
                b[i][0]--;
                s--;
            }
            i++;
        }
        return total;
    }
};