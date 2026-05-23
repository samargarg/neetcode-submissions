class MinStack {
    vector<int> mystack;
    vector<int> mini;
public:
    MinStack() {
        mystack.clear();
        mini.clear();
    }
    
    void push(int val) {
        mystack.push_back(val);
        if (mini.empty() || mystack[mini[mini.size()-1]] > val) {
            mini.push_back(mystack.size()-1);
        }
    }
    
    void pop() {
        if (mystack.size()) {
            mystack.pop_back();
            if (!mini.empty() && mini[mini.size()-1] == mystack.size()) {
                mini.pop_back();
            }
        }
    }
    
    int top() {
        return mystack[mystack.size()-1];
    }
    
    int getMin() {
        return mystack[mini[mini.size()-1]];
    }
};
