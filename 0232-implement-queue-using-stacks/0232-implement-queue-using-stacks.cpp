class MyQueue {
public:
    std::stack<int> inputStack;
    std::stack<int> outputStack;

    MyQueue() {
    
    }

    void push(int x) {
        inputStack.push(x); 
    }

    int pop() {
        transferIfNeeded(); 
        int front = outputStack.top();
        outputStack.pop();
        return front;
    }

    int peek() {
        transferIfNeeded();
        return outputStack.top(); 
    }

    bool empty() {
        return inputStack.empty() && outputStack.empty(); 
    }

private:
    void transferIfNeeded() {
        if (outputStack.empty()) {
            while (!inputStack.empty()) {
                outputStack.push(inputStack.top());
                inputStack.pop();
            }
        }
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