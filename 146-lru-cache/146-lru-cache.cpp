class LRUCache {
public:
    class node{
        public:
        int data;
        int key;
        node * next;
        node * pre;
        node(int d,int k){
            data =d;
            key = k;
        }
        
    };
    node * head = new node(-1,-1);
    node * tail = new node(-1,-1);
    int cap;
    unordered_map<int,node*>cache;
    
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->pre = head;
    }
    void addnode(node * d){
        node * t  =head->next;
        head->next = d;
        d->pre= head;
        d->next =t;
        t->pre = d;
    }
    void deleteNode( node * d ){
        d->pre->next = d->next;
        d->next->pre = d->pre;
        d->next=NULL;
        d->pre=NULL;
    }
    int get(int key) {
        if( cache.find(key)==cache.end() )return -1;
        node * t = cache[key];
        int res = t->data;
        deleteNode(t);
        addnode(t);
        cache[key]=head->next;
        return res;
    }
    
    void put(int key, int value) {
        node * t;
        if( cache.find(key)!=cache.end() ){
            t =cache[key];
            cache.erase(key);
            deleteNode(t);    
        }
        if( cache.size()==cap ){
            cache.erase( tail->pre->key );
            deleteNode(tail->pre);
        }
        addnode(new node(value,key));
        cache[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */