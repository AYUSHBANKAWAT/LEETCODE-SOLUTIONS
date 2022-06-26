class MinStack {
 vector<int> a,b;
public:
    MinStack() {
        a=b={};
    }
    
    void push(int val) {
         a.push_back(val);
        if(b.empty()) b.push_back(val);
        else {
            int newMin = min(val, b.back());
            b.push_back(newMin);
        }
    }
    
    void pop() {
        a.pop_back();
        b.pop_back();
        
    }
    
    int top() {
        return a.back();
    }
    
    int getMin() {
        return b.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */