class BrowserHistory {
public:
    vector<string> history;
    int current;
    int length;
    BrowserHistory(string homepage) {
        history.clear();
        history.push_back(homepage);
        current = 0;
        length = 1;
    }
    
    void visit(string url) {
        if (length < history.size() || current < length-1) {
            history[current+1] = url;
        } else {
            history.push_back(url);
        }
        current++;
        length = current+1;
    }
    
    string back(int steps) {
        while (current && steps) {
            current--;
            steps--;
        }
        return history[current];
    }
    
    string forward(int steps) {
        while (current < length-1 && steps) {
            current++;
            steps--;
        }
        return history[current];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */