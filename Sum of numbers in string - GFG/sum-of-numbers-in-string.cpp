//{ Driver Code Starts
// C++ program to calculate sum of all numbers present
// in a string containing alphanumeric characters
#include <iostream>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to calculate sum of all numbers present in a string.
    int findSum(string str)
    {
    	
    	int sum=0;
    	int i=0;
    	while( i<str.size() ){
    	    int newSum=0;
    	    while( i<str.size() and str[i]>='0' and str[i]<='9'){
    	        newSum=newSum*10+(str[i]-'0');
    	        i++;
    	    }
    	    while( i<str.size() and !(str[i]>='0' and str[i]<='9'))i++;
    	    sum+=newSum;
    	}
    	return sum;
    	
    	
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
	// input alphanumeric string
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin>>str;
	    Solution obj;
	    cout << obj.findSum(str);
        cout<<endl;
	}
	return 0;
}

// } Driver Code Ends