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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL)
            return head;
        ListNode* headNew=new ListNode(0);
        headNew->next=head;
        while(head->next!=NULL){
            ListNode* temp=head->next;
            head->next=head->next->next;
            temp->next=headNew->next;
            headNew->next=temp;
        }
        return headNew->next;    
    }
};