class MyStack {
public:
    queue<int> a;
    queue<int> b;
    int n;
    MyStack() {
        a = {};
        n = 0;
    }
    
    void push(int x) {
        a.push(x);
        n++;
    }
    
    int pop() {
        int x;
        for (int i = 0; i < n; i++) {
            x = a.front();
            if (i != n-1) {
                a.push(x);
            }
            a.pop();
        }
        n--;
        return x;
    }
    
    int top() {
        int x;
        for (int i = 0; i < n; i++) {
            x = a.front();
            a.push(x);
            a.pop();
        }
        return x;
    }
    
    bool empty() {
        return n == 0;
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