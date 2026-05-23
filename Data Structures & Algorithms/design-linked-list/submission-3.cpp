class ListNode {
public:
    int val = 0;
    ListNode* next = nullptr;
    ListNode* prev = nullptr;
    ListNode(int val_) {
        val = val_;
    }
};

class MyLinkedList {

public:
    ListNode* start;
    ListNode* end;
    int length;
    MyLinkedList() {
        start = nullptr;
        end = nullptr;
        length = 0;
    }
    
    int get(int index) {
        if (index >= length) {
            return -1;
        }
        ListNode* node = start;
        for (int i = 0; i < index; i++) {
            node = node->next;
        }
        return node->val;
    }
    
    void addAtHead(int val) {
        ListNode* n = new ListNode(val);
        if (!start) {
            start = n;
            end = n;
        } else {
            n->next = start;
            start->prev = n;
            start = n;
        }
        length++;
    }
    
    void addAtTail(int val) {
        ListNode* n = new ListNode(val);
        if (!end) {
            start = n;
            end = n;
        } else {
            n->prev = end;
            end->next = n;
            end = n;
        }
        length++;
    }

    void addAtIndex(int index, int val) {
        if (index == 0) {
            addAtHead(val);
        } else if (index < length) {
            ListNode* node = start;
            for (int i = 0; i < index; i++) {
                node = node->next;
            }
            ListNode* n = new ListNode(val);
            n->next = node;
            n->prev = node->prev;
            if (node->prev) {
                node->prev->next = n;
            }
            node->prev = n;
            length++;
        } else if (index == length) {
            addAtTail(val);
        }
    }
    
    void deleteAtIndex(int index) {
        if (index >= length) {
            return;
        }

        ListNode* node = start;
        for (int i = 0; i < index; i++) {
            node = node->next;
        }
        if (node->prev) {
            node->prev->next = node->next;
        } else {
            start = node->next;
        }
        if (node->next) {
            node->next->prev = node->prev;
        } else {
            end = node->prev;
        }
        length--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */