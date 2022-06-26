class StockSpanner {
public:
   // int max=INT_MIN,min=INT_MAX;
    class Node{
        public:
        int data;
        int span;
        Node* nex;
        Node* pre;
        Node(int d){
            data =d;
            span=1;
        }  
    };
    Node*head = new Node(INT_MAX);
    Node*tail = new Node(INT_MAX);
    StockSpanner() {
        head->nex = tail;
        tail->pre = head;
        head->pre = NULL;
        tail->nex = NULL;
    }
    int spanCheck(Node*p){
        Node*t=p;
        int count=0;
        while( t!=head ){
            if( t->data<=p->data ){
               count++; 
               t=t->pre; 
            }
            else return count;
           
        }
        return count;
    }
    void insert( Node*p ){
        p->pre=tail->pre;
        p->nex=tail;
        tail->pre->nex=p;
        tail->pre=p;
        p->span=spanCheck(p);
    }
    int next(int price) {
        Node*p = new Node(price);
        insert(p);
        return p->span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */