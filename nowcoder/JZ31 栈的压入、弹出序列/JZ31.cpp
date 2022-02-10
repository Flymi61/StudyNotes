class Solution {
    //˼·��
    //
public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV) {
        stack<int> st;
        //���ڱ���vector 
        size_t pushi = 0, popj = 0;
        while (pushi < pushV.size())
        {
            st.push(pushV[pushi]);
            //���ջ��Ԫ���� popj ָ���popV��������ͬ�����γ�ջֱ������ͬ
            while (!st.empty() && st.top() == popV[popj])
            {
                st.pop();
                popj++;
            }
            pushi++;
        }

        if (st.empty())
        {
            return true;
        }
        return false;
    }
};