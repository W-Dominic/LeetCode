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
    ListNode* middleNode(ListNode* head) {
        int length = 0;
        int mid_index = 0;
        ListNode* curr = head;
        int curr_index = 0;
        
        while(head->next != NULL){
            head = head -> next;
            length ++;
            mid_index = length / 2;
            if (curr_index != mid_index) {
                curr = curr->next;
                curr_index ++;
            }
        }
        if (length % 2 == 0) {
            return curr;
        }
        return curr->next;
    }
};
