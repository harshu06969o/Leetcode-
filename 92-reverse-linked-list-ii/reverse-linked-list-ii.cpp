class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        ListNode dummy(0);
        dummy.next = head;

        // Find node immediately before left
        ListNode* beforeLeft = &dummy;

        for (int i = 1; i < left; i++) {
            beforeLeft = beforeLeft->next;
        }

        // Identify sublist boundaries
        ListNode* segmentStart = beforeLeft->next;
        ListNode* afterRight = segmentStart;

        for (int i = 0; i < right - left + 1; i++) {
            afterRight = afterRight->next;
        }

        // Reverse the selected sublist
        ListNode* prev = afterRight;
        ListNode* curr = segmentStart;

        while (curr != afterRight) {

            ListNode* nextNode = curr->next;

            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // Connect reversed sublist to the original list
        beforeLeft->next = prev;

        return dummy.next;
    }
};