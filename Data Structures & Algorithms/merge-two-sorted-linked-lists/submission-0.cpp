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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* head= new ListNode();

        ListNode* node1 =list1;
        ListNode* node2 = list2;
        ListNode* node3 =head;

        while( node1!=NULL && node2!=NULL){
            if( node1->val <= node2->val){
                node3->next= node1;
                node1=node1->next;
                node3=node3->next;
                
            } 
            else {
                 node3->next= node2;
                node2=node2->next;
                node3= node3->next;
                
            }

        }

        if( node1==NULL){
            node3->next= node2;
        }else{
            node3->next =node1;
        }

        return head->next;
    }
};
