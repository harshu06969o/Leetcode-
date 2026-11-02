/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n1=0, n2=0;
         ListNode* temp1=headA;
          ListNode* temp2 = headB;
          while( temp1!=nullptr){
            n1++;
            temp1=temp1->next;
          }
           while( temp2!=nullptr){
            n2++;
            temp2=temp2->next;
          }

          ListNode* smallerNode;
          ListNode* biggerNode;
          if( n1>n2){
            smallerNode = headB;
            biggerNode = headA;
          }
           else if( n2>=n1){
            smallerNode= headA;
            biggerNode = headB;

           }
            int diff= abs( n1-n2);
            for ( int i =0;i<diff;i++){
                biggerNode = biggerNode->next;
                
            }
            while( smallerNode!=biggerNode){
                smallerNode= smallerNode->next;
                biggerNode = biggerNode->next;
            }
            return smallerNode;

    }
};