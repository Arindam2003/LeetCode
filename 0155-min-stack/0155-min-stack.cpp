class MinStack {
    stack<int> st;
    stack<int> minst;

public:
    MinStack() {
        while (!st.empty()) {
            st.pop();
        }
        while (!minst.empty()) {
            minst.pop();
        }
    }

    void push(int val) {
        st.push(val);
        if (minst.size() > 0) {
            int mini = min(minst.top(), val);
            minst.push(mini);
        } else {
            minst.push(val);
        }
    }

    void pop() {
        st.pop();
        minst.pop();
    }

    int top() { return st.top(); }

    int getMin() { return minst.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */