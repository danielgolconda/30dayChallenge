class MinStack {
public:
    stack <pair<int,int>> st;
    MinStack() {
        
    }
    
    void push(int x) {
        if(st.empty())
        {
            st.push({x,x});
        }
        else
        {
            int t=st.top().second;
            t = min(t,x);
            st.push({x,t});
        }
    }
    
    void pop() {
        if(st.empty() == false)
        {
            st.pop();
        }
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
