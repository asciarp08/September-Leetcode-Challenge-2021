/**
Time = O(n+k)
Space = O(k)
**/

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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        
        ListNode* cur = head;
        while(cur!=NULL){
            cur = cur->next;
            n++;
        }
        
        int len = n/k;
        int extraNodes = n%k;
        cur = head;
        vector<ListNode*> ans;
        
        while(cur!=NULL){
            int curLen = len+(extraNodes>0?1:0);
            ans.push_back(cur);
            ListNode* prev = cur;
            while(curLen-- && cur!=NULL){
                prev = cur;
                cur = cur->next;
            }
            extraNodes--;
            prev->next = NULL;
        }
        
        while(ans.size()<k){
            ans.push_back(NULL);
        }
        return ans;
    }
};
