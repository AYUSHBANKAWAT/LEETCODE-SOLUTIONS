class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>s;
    int n = intervals.size();
    sort(intervals.begin(),intervals.end());
    s.push_back( intervals.front());
    for( int i=1;i<n;i++ ){
        if( s.back().back()<intervals[i].front()){
            s.push_back(intervals[i]);
        }else{
         int start = s.back().front()<=intervals[i].front()?s.back().front():intervals[i].front();
         int end = s.back().back() > intervals[i].back()?s.back().back():intervals[i].back();
         vector<int>temp ={start,end};
         s.pop_back();
         s.push_back(temp);   
        }
    }
    
    //sort(ans.begin(),ans.end(),cmp);
    return s;
    }
};