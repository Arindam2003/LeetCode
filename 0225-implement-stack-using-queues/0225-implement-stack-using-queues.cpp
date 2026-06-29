class MyStack {
public:
    queue<int> q;

    MyStack() { 
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        // pop n-1 ele and push to helper q
        int n=q.size();
        for(int i=0;i<n-1;i++)
        {
            // pop from q
            int frnt=q.front();
            q.push(frnt);
            q.pop();
        }
        // pop the last elele in main  q
        int ans=q.front();
        q.pop();

        return ans;
    }
    
    int top() {
        // pop n-1 ele and push to helper q
        int n=q.size();
        for(int i=0;i<n-1;i++)
        {
            // pop from q1
            int frnt=q.front();
            q.push(frnt);
            q.pop();
        }
        // pop the last elele in main  q
        int ans=q.front();
        q.pop();
        q.push(ans);
        return ans;
    }
    
    bool empty() {
        if(q.size()==0)
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