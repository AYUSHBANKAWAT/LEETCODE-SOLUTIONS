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
        cout << node->data <<" "; 
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
class Solution{
public:
    Node* divide(int N, Node *head){
        Node * t =head;
        if(N==0 or N==1)return head;
        if( N==2){
            if(head->data%2==0){
                return head;
            }else {
                if(head->next->data%2!=0){
                    return head;
                }else{
                    Node* p=head->next;
                    head->next->next=head;
                    head->next=nullptr;
                    return p;
                }
            }
        }
        Node* o =new Node(-1);
        o->next=head;
        head=o;
        int r=0;
        while(t->next!=nullptr){t=t->next;r++;}
        Node* p=head;
        int i=0;
        while( i<N and p!=nullptr and p->next!=nullptr){
            if(p->next->data%2!=0){
                Node*m=p->next;
                if(m->next==nullptr)break;
                p->next = m->next;
                t->next =m;
                t=t->next;
                m->next=nullptr;
               // p=p->next;
            }
            else p=p->next;
           // cout<<p->next->data<<"  "<<t->data<<endl;
            i++;
        }
        // if( p->next and p->next->data%2!=0){
        //     Node * u=p->next;
        //     p->next=u->next;
        //     t->next=u;
        //     u->next=nullptr;
        // }
        return head->next;
        
    }
};

//{ Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}

// } Driver Code Ends