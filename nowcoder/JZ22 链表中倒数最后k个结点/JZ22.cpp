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
     * @param pHead ListNode��
     * @param k int����
     * @return ListNode��
     */
    ListNode* FindKthToTail(ListNode* pHead, int k) {
        // write code here

        //ǰ��ָ�뷨
        ListNode* cur = pHead;
        ListNode* pos = pHead;
        while (k && cur)
        {
            cur = cur->next;
            k--;
        }
        if (cur == nullptr && k != 0)
            return cur;
        while (cur)
        {
            cur = cur->next;
            pos = pos->next;
        }
        return pos;
    }
};