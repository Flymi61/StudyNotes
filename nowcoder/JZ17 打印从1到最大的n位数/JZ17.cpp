class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param n int���� ���λ��
     * @return int����vector
     */
    vector<int> printNumbers(int n) {
        // write code here
        vector<int> vc;
        int num = 1;
        while (n--)
        {
            num *= 10;
        }
        vc.resize(num - 1);
        for (int i = 1; i < num; i++)
        {
            vc[i - 1] = i;
        }
        return vc;
    }
};