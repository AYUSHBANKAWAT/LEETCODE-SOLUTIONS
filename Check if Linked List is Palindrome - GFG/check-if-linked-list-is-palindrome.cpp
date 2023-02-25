//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    //Function to check whether the list is palindrome.
    Node* getMiddle(Node* head){
        Node*s=head;
        Node* f=head;
        Node*t;
        while(f!=nullptr and f->next!=nullptr){
            t=s;
            s=s->next;
            f=f->next->next;
        }
        return f==nullptr?t:s;
    }
    Node* reverse(Node* h){
        Node*t=h;
         Node*t2=h->next;
        t->next=nullptr;
       
        while(t2!=nullptr){
            Node*temp=t2->next;
            t2->next=t;
            t=t2;
            t2=temp;
        }
        return t;
    }
    
    bool comp(Node*h1,Node*h2){
        while(h1!=nullptr and h2!=nullptr){
            if(h1->data!=h2->data)return false;
            h1=h1->next;
            h2=h2->next;
        }
        return true;
    }
    void printLL(Node*h){
        while(h!=nullptr){
            cout<<h->data<<" ";
            h=h->next;
        }
        cout<<endl;
    }
    bool isPalindrome(Node *head)
    {
        if(head==nullptr)return true;
        if(head->next==nullptr)return true;
        if( head->next->next==nullptr ){
            return head->data==head->next->data;
        }
        Node * mid=getMiddle(head);
       // cout<<mid->data;
    
        Node * head1=reverse(mid->next);
        mid->next=nullptr;
       // printLL(head);
       // printLL(head1);
        return comp(head,head1);
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends