class MyStack {

    //��֤����һ������Ϊ��
public:
    MyStack() {

    }

    void push(int x)
    {
        if (!_q1.empty())
        {
            while (!_q2.empty())
            {
                _q1.push(_q2.front());
                _q2.pop();
            }
            _q1.push(x);
        }
        else
        {
            while (!_q1.empty())
            {
                _q2.push(_q1.front());
                _q1.pop();
            }
            _q2.push(x);
        }

    }

    //ת��ǰ n - 1 �����ݣ�ɾ�����һ�����ݼ���
    int pop() {
        if (_q1.empty())
        {
            while (_q2.size() != 1)
            {
                _q1.push(_q2.front());
                _q2.pop();
            }
            int val = _q2.front();
            _q2.pop();
            return val;
        }
        else
        {
            while (_q1.size() != 1)
            {
                _q2.push(_q1.front());
                _q1.pop();
            }
            int val = _q1.front();
            _q1.pop();
            return val;
        }

    }

    //�������һ�����ݼ���
    int top() {
        if (_q1.empty())
        {
            return _q2.back();
        }
        else
        {
            return _q1.back();
        }
    }

    bool empty() {
        return _q1.empty() && _q2.empty();
    }
    // �ֱ�������/������
    queue<int> _q1;
    queue<int> _q2;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */