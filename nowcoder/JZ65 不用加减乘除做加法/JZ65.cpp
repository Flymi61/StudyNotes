class Solution {
public:
    int Add(int num1, int num2) {
        if (num1 == 0)
            return num2;
        if (num2 == 0)
            return num1;
        //λ���㡪��������
        //���
        int result1 = num1 ^ num2;
        //��λ��
        int result2 = (num1 & num2) << 1;
        //��ǰ����������
        return Add(result1, result2);
    }
};