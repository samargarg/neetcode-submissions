class BrowserHistory {
public:
    stack<string> past, fut;
    string current;
    BrowserHistory(string homepage) {
        current = homepage;
    }
    
    void visit(string url) {
        past.push(current);
        current = url;
        fut = {};
    }
    
    string back(int steps) {
        while (steps && !past.empty()) {
            steps--;
            fut.push(current);
            current = past.top();
            past.pop();
        }
        return current;
    }
    
    string forward(int steps) {
        while (steps && !fut.empty()) {
            steps--;
            past.push(current);
            current = fut.top();
            fut.pop();
        }
        return current;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */