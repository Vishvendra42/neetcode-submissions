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
        
        ListNode* newHead =new ListNode();

        ListNode*node = head;
       

        while( node!=NULL){
            ListNode* temp = newHead->next;
            ListNode* temp2=newHead;

            temp2->next= node;
             node= node->next;
             temp2=temp2->next;
             
            temp2->next = temp;

        }
        return newHead->next;
    }
};
