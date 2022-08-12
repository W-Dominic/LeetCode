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
    bool hasCycle(ListNode *head) {
        if (head == NULL) return false;
        unordered_set<ListNode*> nodes;
        //traverse the list adding to the set of nodes
        while(nodes.find(head) == nodes.end() && head != NULL){
            nodes.insert(head);
            head = head->next;
        }
        //if a node is found that already exists in the set, then we return true
        if (head != NULL){
            return true;
        }
        return false;
    }
};
