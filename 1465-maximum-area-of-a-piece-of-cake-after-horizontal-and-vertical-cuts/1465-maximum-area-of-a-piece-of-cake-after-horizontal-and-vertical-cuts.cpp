class Solution {
public:
    int maxArea(int h, int w, vector<int>& hC, vector<int>& vc) {
        
        int maxht=0;
        int maxwt=0;
        int i=0;
        sort(hC.begin(),hC.end());
        sort(vc.begin(),vc.end());
        hC.push_back(h);
        vc.push_back(w);
        for( auto a:hC ){
            int diff=a-i;
            maxht = maxht>diff?maxht:diff;
            i=a;
        }
        i=0;
        for( auto a:vc ){
            int diff=a-i;
            maxwt = maxwt>diff?maxwt:diff;
            i=a;
        }
        
        return (1LL*maxwt*maxht)%1000000007;
        
    }
};