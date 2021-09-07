/**
Time = O(n)
Space = O(1)
**/
/**Iterative**/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        ListNode* prev = NULL;
        
        while(head!=NULL){
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};

/** Recursive **/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        return helper(head, NULL);
    }
    
    ListNode* helper(ListNode* head, ListNode* prev){
        if(head==NULL){
            return prev;
        
        }
        ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        
        return helper(head, prev);
        
    }
};
