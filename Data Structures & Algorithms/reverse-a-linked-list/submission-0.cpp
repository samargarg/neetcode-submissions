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
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        ListNode *ptr = head;
        vector<int> values;
        while (ptr != nullptr) {
            values.push_back(ptr->val);
            ptr = ptr->next;
        }
        reverse(values.begin(), values.end());
        ListNode* topMost = new ListNode(values[0]);;
        ListNode *prevNode = topMost;
        for (int i = 1; i < values.size(); i++) {
            ListNode *node = new ListNode(values[i]);
            prevNode->next = node;
            prevNode = node;
        }
        return topMost;

        
    }
};
