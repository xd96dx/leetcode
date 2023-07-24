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
        int n = 0;
        for (ListNode* node = head; node->next != nullptr; node=node->next) {
            n++;
        }
        ListNode* node = head;
        n = n%2 ? n/2+1 : n/2;
        for (int i = 0; i < n; i++) {
            node = node->next;
        }
        return node;
    }
};
