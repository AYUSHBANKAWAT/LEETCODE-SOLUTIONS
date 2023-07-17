//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
       // lonhgtes length balanced subst 
       if( x.size()%2!=0 )return false;
       stack<char>s;
       for( int i=0;i<x.size();i++ ){
           if( x[i]=='{' or x[i]=='[' or x[i]=='(' ){
               s.push(x[i]);
           }
           else{
               if( s.empty() )return false;
               if( x[i]=='}' ){
                   if( s.top()=='{' ){
                       s.pop();
                   }else{
                       return false;
                   }
               }
               else if( x[i]==']' ){
                   if( s.top()=='[' ){
                       s.pop();
                   }else{
                       return false;
                   }
               }
               else if( x[i]==')' ){
                   if( s.top()=='(' ){
                       s.pop();
                   }else{
                       return false;
                   }
               }
               else continue;
           }
       }
       return true;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends