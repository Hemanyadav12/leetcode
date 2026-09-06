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
    int pairSum(ListNode* head) {
        int maxsum = INT_MIN;
        vector<ListNode*> v;
        ListNode* temp = head;
        while(temp){
            v.push_back(temp);
            temp = temp->next;
        }
        int n = v.size();
        for(int i=0; i<=(n/2)-1; i++){
            int sum = v[i]->val + v[n-1-i]->val;
            maxsum = max(sum, maxsum);
        }
        return maxsum;
    }
};