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
        ListNode* newHead = new ListNode();

        ListNode* node = head;

        while (node != NULL) {
            ListNode* temp = newHead->next;
            ListNode* temp2 = newHead;

            temp2->next = node;
            node = node->next;
            temp2 = temp2->next;

            temp2->next = temp;
        }
        return newHead->next;
    }
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL) return ;

        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // now  the other half will means right part will be reversed and then add to  first one by
        //    one by one as the order we want
        ListNode* rev = reverseList(slow->next);
        slow->next = NULL;
        ListNode* node = head;
        while (rev != NULL) {
            ListNode* temp = node->next;
            node->next = rev;

            node = node->next;
            rev = rev->next;

            node->next = temp;
            node=node->next;
        }

        return ;
    }
};
