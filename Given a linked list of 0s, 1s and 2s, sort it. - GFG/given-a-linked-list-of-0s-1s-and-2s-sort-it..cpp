//{ Driver Code Starts
#include <bits/stdc++.h>

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

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    void putInFront(Node*h,Node*l){
        
    }
    void putInBack(Node*h,Node*l){
        
    }
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
       Node*t=head;
       Node*z=new Node(0);
       Node*z1 = z;
       Node*o=new Node(1);
       Node* o1=o;
       Node*to=new Node(2);
       Node* to1=to;
       while( t!=nullptr ){
           Node* d = t->next;
           if( t->data==0 ){
              z1->next = t;
              t->next = nullptr;
              z1=z1->next;
              t=d;
           }else if(t->data==1){
               o1->next = t;
               t->next = nullptr;
               o1=o1->next;
               t=d;
           }else{
               to1->next = t;
               t->next = nullptr;
               to1=to1->next;
               t=d;
           }
       }
       if( z->next==nullptr ){
           if( o->next==nullptr ){
               return to->next;
           }
           else{
               o=o->next;
               o1->next=to->next;
               return o;
           }
       }
       else{
           if( o->next==nullptr ){
               z=z->next;
               z1->next = to->next;
               return z;
           }
           else{
               z=z->next;
               z1->next=o->next;
               o1->next = to->next;
               return z;
           }
       }
       
       return z;
       
        
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends