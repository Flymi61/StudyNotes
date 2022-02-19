/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        //����һ:����
        vector<int> ve;
        while (head != nullptr)
        {
            ve.push_back(head->val);
            head = head->next;
        }
        std::reverse(ve.begin(), ve.end());
        return ve;
        //���������ݹ�
        //��������ջ
        /*stack<int> st;
        vector<int> ve;
        while(head != nullptr)
        {
            st.push(head->val);
            head = head -> next;
        }
        while(!st.empty())
        {
            ve.push_back(st.top());
            st.pop();
        }
        return ve;*/
    }
};