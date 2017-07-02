class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int flag = 0;
        ListNode *head = new ListNode(0);
        ListNode *curr = head;
        while (l1 || l2 || flag) {
            int val = flag;
            if (l1) { val += l1->val; l1 = l1->next; }
            if (l2) { val += l2->val; l2 = l2->next;}
            flag = val / 10;
        	curr->next = new ListNode(val % 10);
        	curr = curr->next;
        }
        return head->next;
    }
};