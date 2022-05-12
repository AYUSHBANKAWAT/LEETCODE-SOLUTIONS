class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int i=nums2.size()-1;
        stack<int>s;
        vector<int>nm(nums2.size(),0);
        while( i<nums2.size()){
            while( !s.empty() && nums2[i]>s.top() )s.pop();
            if(s.empty())nm[i]=-1;
            else nm[i]=s.top();
            s.push(nums2[i]);
            i--;
        }
        int j=0;
        vector<int>ans;
        while( j<nums1.size()){
            auto itr = find(nums2.begin(),nums2.end(),nums1[j]);
            if( itr==nums2.end()){
                ans.push_back(-1);
            }else{
                int k = itr - nums2.begin();
                ans.push_back(nm[k]);
            }
            j++;
        }
        return ans;
    }
};