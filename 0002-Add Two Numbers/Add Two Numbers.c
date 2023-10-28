/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
        int carry=0;
        struct ListNode* dummy = (struct ListNode*) malloc(sizeof(struct ListNode));
        dummy->val=0;
        dummy->next=NULL;
        struct ListNode* temp=dummy;
        while(l1!=NULL || l2!=NULL || carry!=0) {
            int sum=0;
            if(l1!=NULL) {
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL) {
                sum+=l2->val;
                l2=l2->next;
            }
            sum+=carry;
            carry=sum/10;
            struct ListNode* newNode = (struct ListNode*) malloc(sizeof(struct ListNode));
            newNode->val=sum%10;
            newNode->next=NULL;
            temp->next=newNode;
            temp=newNode;
        }
        return dummy->next;
}
