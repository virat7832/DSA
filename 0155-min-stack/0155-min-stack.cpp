class MinStack {
private:
    stack<long> st;  
    long min;        

public:
    MinStack() {
        min = LONG_MAX;  
    }

    void push(int val) {
        long value = (long)val;  
        if (st.empty()) {
            min = value;
            st.push(value);
        } else {
            if (value >= min) {
                st.push(value);
            } else {
                st.push(2 * value - min);  
                min = value;
            }
        }
    }

    void pop() {
        if (st.empty()) return;
        long val = st.top();
        st.pop();
        if (val < min) {
            min = 2 * min - val;  
        }
    }

    int top() {
        
        long val = st.top();
        return (val < min) ? (int)min : (int)val;
    }

    int getMin() {
       
        return (int)min;
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