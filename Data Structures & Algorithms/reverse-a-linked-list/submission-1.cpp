/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {

    pair<ListNode*, ListNode*> myrev(ListNode* head) {
        if (head == nullptr) {
            return {head, head};
        }
        pair<ListNode*, ListNode*> p = myrev(head->next);
        if (p.first == nullptr) {
            return {head, head};
        }
        p.second->next = head;
        head->next = nullptr;
        return {p.first, head};
    }

public:
    ListNode* reverseList(ListNode* head) {
        return myrev(head).first;
    }
};
