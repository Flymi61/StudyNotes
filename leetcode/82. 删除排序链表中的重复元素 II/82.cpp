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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr)
            return nullptr;
        ListNode* cur = head;
        while (cur && cur->next && cur->val == cur->next->val)
        {
            cur = cur->next;
        }
        if (cur == head)
            head->next = deleteDuplicates(cur->next);
        else
            head = deleteDuplicates(cur->next);
        return head;
    }
};