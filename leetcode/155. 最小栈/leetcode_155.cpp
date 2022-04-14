class MinStack {
public:
    MinStack() {

    }

    void push(int val) {
        //��ջΪ�գ������ջ��������Сջ��ջ��Ԫ��С��ȣ�������Сջ
        if (st.empty() || val <= min_st.top())
        {
            min_st.push(val);
        }
        st.push(val);
    }

    void pop() {
        //��ջ��Ԫ��С�ڻ������Сջջ��Ԫ�أ������ջ
        if (st.top() <= min_st.top())
        {
            min_st.pop();
        }
        st.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return min_st.top();
    }

    //��������ջ
    stack<int> st;      //���ڱ���������ջԪ��
    stack<int> min_st;  //���ڱ��浱ǰջ����СԪ�أ�����ջջ��Ԫ��
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */










