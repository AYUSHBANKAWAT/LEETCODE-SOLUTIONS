class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        unordered_map<char, int> umap = {
		{'I', 1},
		{'V', 5},
		{'X', 10},
		{'L', 50},
		{'C', 100},
		{'D', 500},
		{'M', 1000}};
        int result=0;
        result=result+umap[s[n-1]];
        for( int i=n-1;i>0;i-- ){
            if( umap[s[i-1]]>=umap[s[i]] ){
                result+=umap[s[i-1]];
            }else if( umap[s[i-1]]<umap[s[i]] ){
                result-=umap[s[i-1]];
            }
        }
        return result;
    }
};