#include <iostream>
#include<bits/stdc++.h>
using namespace std;

static bool comp(pair<int,int>p1,pair<int,int>p2){
    if( p1.second==p2.second ){
        return p1.first<p2.first;
    }else{
        return p1.second>p2.second;
    }
}

int main() {
	//code
	int t;
	cin>>t;
	while(t){
	    int n;
	    cin>>n;
	   // vector<int>arr(n);
	   map<int,int>mp;
	    for( int i=0;i<n;i++ ){
	        int k;
	        cin>>k;
	        mp[k]++;
	    }
	    int i=0;
	    vector<pair<int,int>>p(mp.size());
	    for( auto itr= mp.begin();itr!=mp.end();itr++ ){
	        p[i].first=itr->first;
	        p[i].second=itr->second;
	        i++;
	    }
	    i=0;
	    sort( p.begin(),p.end(),comp );
	    vector<int>ans;
	    for(  i=0;i<p.size();i++ ){
	        for( int j=0;j<p[i].second;j++ ){
	            ans.push_back(p[i].first);
	        }
	    }
	    for( auto a:ans )cout<<a<<" ";
	    cout<<endl;
	    t--;
	}
	return 0;
}