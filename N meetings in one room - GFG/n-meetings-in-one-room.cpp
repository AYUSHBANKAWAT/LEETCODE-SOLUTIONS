// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    
    public:
    
    class meet{
        public:
        int start;
        int end;
        int pos;
    };
    static bool comp(meet m1,meet m2){
        if( m1.end<m2.end)return true;
        else return false;
        //else if( m1.pos<m2.pos)return true;
        //return false;
        
    }
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        meet m[n];
        for( int i=0;i<n;i++){
            m[i].start = start[i],m[i].end = end[i],m[i].pos = i+1;
        }
        sort( m,m+n,comp);
       // vector<int>maxMeet;
        int limit = m[0].end;
        //maxMeet.push_back(m[0].pos);
        int count=1;
        for( int i=1;i<n;i++){
            if( m[i].start>limit){
                limit = m[i].end;
                count++;
               // maxMeet.push_back(m[i].pos);
            }
        }
        return count;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends