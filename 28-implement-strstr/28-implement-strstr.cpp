#define prime 2
#define ll long long int 
#define BASE 10000000
class Solution {
public:
    ll createHash( string s,int n ){
        ll result=0;
        for( int i=0;i<n;i++ ){
            result+=(ll)((s[i]*(ll)pow(prime,i))%BASE);
        }
        return result;
    }
    ll recalculateHash(string s,ll OldHash,int oldIndex,int newIndex,int patLength){
        ll newHash = OldHash-s[oldIndex];
        newHash = newHash/prime;
        newHash+=(ll)((s[newIndex]*(ll)pow(prime,patLength-1)%BASE));
        return newHash;
    }
    bool checkEqual(string s1,string s2,int ind1,int end1,int ind2,int end2){
        if( end1-ind1!=end2-ind2 )return false;
        while( ind1<=end2 and ind2<=end2 ){
            if( s1[ind1]!=s2[ind2] )return false;
            ind1++;
            ind2++;
        }
        return true;
    }
    int strStr(string haystack, string needle) {
        int n=needle.size();
        ll needleHash = createHash(needle,n);
        int i=0;
        int n2 = haystack.size();
        ll hsHash = createHash(haystack,n);
        for( int i=0;i<=n2-n;i++ ){
            if( needleHash==hsHash and checkEqual(haystack,needle,i,i+n-1,0,n-1) ){
                return i;
            }
            if( i<n2-n ){
                hsHash=recalculateHash(haystack,hsHash,i,i+n,n);
            }
        }
        return -1;
    }
};