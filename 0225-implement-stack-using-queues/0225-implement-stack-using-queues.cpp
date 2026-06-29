class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    MyStack() { 
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        // pop n-1 ele and push to helper q
        int n=q1.size();
        for(int i=0;i<n-1;i++)
        {
            // pop from q1
            int frnt=q1.front();
            q2.push(frnt);
            q1.pop();
        }
        // pop the last elele in main  q
        int ans=q1.front();
        q1.pop();
        // exchange main and helper q
        swap(q1,q2);
        return ans;
    }
    
    int top() {
        // pop n-1 ele and push to helper q
        int n=q1.size();
        for(int i=0;i<n-1;i++)
        {
            // pop from q1
            int frnt=q1.front();
            q2.push(frnt);
            q1.pop();
        }
        // pop the last elele in main  q
        int ans=q1.front();
        q1.pop();
        q2.push(ans);
        // exchange main and helper q
        swap(q1,q2);
        return ans;
    }
    
    bool empty() {
        if(q1.size()==0)
        {
            return true;
        }else {
            return false;
        }
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */