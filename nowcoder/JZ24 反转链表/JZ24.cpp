/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};*/
/*class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        //����һ����ָ��
        if(pHead == nullptr)
            return nullptr;
        ListNode* cur = pHead;
        ListNode* next1 = cur ->next;
        ListNode* next2 = nullptr;
        while(next1)
        {
            next2 = next1 ->next;
            next1 -> next = cur;
            cur = next1;
            next1 = next2;
        }
        pHead ->next = nullptr;
        return cur;
    }
};*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        //��������ͷ�巨
        //����������pHead���Լ�¼������newheadָ��������ͷ�ڵ�
        if (pHead == nullptr || pHead->next == nullptr)
            return pHead;
        ListNode* newhead = nullptr;
        while (pHead)
        {
            //ȥ��������ͷ�ڵ�
            ListNode* tmp = pHead;
            pHead = pHead->next;
            //���� ������ͷ���
            tmp->next = newhead;
            newhead = tmp;
        }
        pHead = newhead;
        return pHead;
    }
};