/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param head ListNode��
     * @param val int����
     * @return ListNode��
     */
    ListNode* deleteNode(ListNode* head, int val) {
        // write code here
        if (head == nullptr)
            return nullptr;
        if (head->val == val)
            return head->next;
        ListNode* cur = head;
        ListNode* prev = head->next;
        while (prev && prev->val != val)
        {
            cur = prev;
            prev = prev->next;
        }
        if (prev)
        {
            cur->next = prev->next;
        }
        return head;
    }
};