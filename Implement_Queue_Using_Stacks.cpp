class MyQueue {
    stack<int>st,help;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        while(st.size()){
            help.push(st.top());
            st.pop();
        }
        int out=help.top();
        help.pop();
        while(help.size()){
            st.push(help.top());
            help.pop();
        }
        return out;
    }
    
    int peek() {
        while(st.size()){
            help.push(st.top());
            st.pop();
        }
        int front=help.top();
        while(help.size()){
            st.push(help.top());
            help.pop();
        }
        return front;
    }
    
    bool empty() {
        return st.size()==0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */