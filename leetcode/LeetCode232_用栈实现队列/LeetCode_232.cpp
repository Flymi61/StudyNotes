class MyQueue {
public:
    MyQueue() {

    }
    //�����ڳ����е�ջ��Ϊ�գ�������ת�����ݣ��Ա���˳��
    void push(int x) {

        while (!st_pop.empty())
        {
            st_push.push(st_pop.top());
            st_pop.pop();
        }
        st_push.push(x);
    }
    //������ͬ��
    int pop() {
        while (!st_push.empty())
        {
            st_pop.push(st_push.top());
            st_push.pop();
        }
        int val = st_pop.top();
        st_pop.pop();
        return val;
    }

    int peek() {
        while (!st_push.empty())
        {
            st_pop.push(st_push.top());
            st_push.pop();
        }
        return st_pop.top();
    }

    //��ջ��Ϊ�գ������Ϊ��
    bool empty() {
        return st_push.empty() && st_pop.empty();
    }

    
    stack<int> st_push;
    stack<int> st_pop;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */