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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode * headNew=new ListNode(0);
        ListNode * headLast=headNew;
        while(head!=NULL){
            if(head->val!=val){
                headLast->next=head;
                headLast=head;
            }
            head=head->next;
            headLast->next=NULL;
        }
        return headNew->next;
    }
};