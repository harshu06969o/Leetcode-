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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head || head->next==nullptr) return nullptr;
        ListNode dummy(0);
        dummy.next = head;
         
        ListNode* temp = &dummy;
        for(int i =0;i<n;i++){
             temp = temp->next;
        }
        
        ListNode* curr = &dummy;
        while( temp->next!=nullptr){
            curr= curr->next;
            temp = temp->next;

        }
         
        ListNode* del = curr->next ;
        curr->next = curr->next->next;
        delete del;
         return dummy.next;
        
    }
};