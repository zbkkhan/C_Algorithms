/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int i;
    if(head->next == NULL && n == 1){
        return NULL;
    }
    
    //call traverseList on head
    i = traverseList(head, n);
    
    //If first element had to be removed
    if(i == n + 1){
        head = head->next;
    }
    //return head
    return head;
}

int traverseList(struct ListNode* node, int n){
    int i;
    if(node->next == NULL){
        //Will be accessed in second node from last
        return 2;
    }
    
    i = traverseList(node->next, n);
    
    //If node before n-th node 
    if(i == n + 1){
        node->next = node->next->next;
    }
    
    i++;
    return i;
    
}
