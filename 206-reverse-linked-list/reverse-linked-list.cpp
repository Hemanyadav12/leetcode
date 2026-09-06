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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* prev = nullptr;
        ListNode* temp = head;
        ListNode* temp1 = head->next;
        while(temp){
            temp->next = prev;
            prev = temp;
            temp = temp1;
            if(temp1 != nullptr) temp1 = temp1->next;
        }
        return prev;
    }
};