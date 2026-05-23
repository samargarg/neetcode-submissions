class BrowserHistory {

struct ListNode {
    ListNode* next;
    ListNode* prev;
    string url;

    ListNode(string url, ListNode* next = nullptr, ListNode* prev = nullptr) {
        this->url = url;
        this->next = next;
        this->prev = prev;
    }
};

public:

    ListNode* start;
    ListNode* end;
    ListNode* current;

    BrowserHistory(string homepage) {
        start = new ListNode("", nullptr, nullptr);
        end = new ListNode("", nullptr, nullptr);
        current = new ListNode(homepage, end, start);
        start->next = current;
        end->prev = current;
    }
    
    void visit(string url) {
        ListNode* newPage = new ListNode(url);
        newPage->next = end;
        end->prev = newPage;
        current->next = newPage;
        newPage->prev = current;
        current = newPage;
    }
    
    string back(int steps) {
        while (current->prev != start && steps) {
            current = current->prev;
            steps--;
        }
        return current->url;
    }
    
    string forward(int steps) {
        while (current->next != end && steps) {
            current = current->next;
            steps--;
        }
        return current->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */