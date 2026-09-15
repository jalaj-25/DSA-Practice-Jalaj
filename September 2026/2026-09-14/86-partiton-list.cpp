// 86-partiton-list.py;linklist;help-syntax;leetcode

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
    ListNode* partition(ListNode* head, int x) {
        ListNode bHead(0), aHead(0); 
        ListNode* before = &bHead;
        ListNode* after = &aHead;

        while(head) {
            if(head->val < x) { 
                before -> next = head;
                before = before->next;
            } else {
                after->next = head;
                after = after->next;
            }

            head = head->next;
        }

        after->next = nullptr;
        before->next = aHead.next;
        return bHead.next;
    }

};