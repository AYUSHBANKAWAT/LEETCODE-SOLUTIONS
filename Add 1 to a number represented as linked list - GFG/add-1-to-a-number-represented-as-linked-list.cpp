//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    
    public:
    void carry(Node* h,int & c){
        if( h==nullptr )return;
        if( h->next==nullptr ){
            int m = h->data + 1;
            c=m/10;
            m=m%10;
            h->data=m;
            return ;
        }
        carry(h->next,c);
        int m = h->data + c;
        c=m/10;
        m=m%10;
        h->data=m;
        return ;
    }
    Node* addOne(Node *head) 
    {
        int c=0;
        carry(head,c);
        if(c==1){
            Node*r = new Node(1);
            r->next=head;
            head=r;
        }
        return head;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends