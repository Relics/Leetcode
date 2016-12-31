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
    ListNode* findMid(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast) {
            fast = fast->next;
            if (fast && fast->next) {
                fast = fast->next;
                slow = slow->next;
            }
        }
        return slow;
    }
    ListNode* reverse(ListNode* head) {
        if (!head) return NULL;
        ListNode* dummy = new ListNode(-1);
        while (head) {
            ListNode* temp = dummy->next;
            dummy->next = head;
            head = head->next;
            dummy->next->next = temp;
        }
        return dummy->next;
    }
    void mergeTwoLists(ListNode* first, ListNode* second) {
        while (first && second) {
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;
            first->next = second;
            second->next = temp1;
            first = temp1;
            second = temp2;
        }
    }
    void reorderList(ListNode* head) {
        if (!head) return;
        ListNode* mid = findMid(head);
        ListNode* head2 = reverse(mid->next);
        mid->next = NULL;
        mergeTwoLists(head, head2);
    }
};
