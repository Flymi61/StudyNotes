class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param array int����vector
     * @return int����vector
     */
    vector<int> FindNumsAppearOnce(vector<int>& array) {
        // write code here
        //λ����
        int flag = 0;
        for (auto e : array)
        {
            flag ^= e;
        }
        //�ҵ���λΪ1�Ķ�����λ
        int i = 0;
        while (((flag >> i) & 1) == 0)
        {
            i++;
        }
        //
        flag = flag & (1 << i);
        vector<int> vc;
        vc.resize(2);
        for (auto e : array)
        {
            if (e & flag)
            {
                vc[0] ^= e;
            }
            else
            {
                vc[1] ^= e;
            }
        }
        if (vc[0] > vc[1])
            std::swap(vc[0], vc[1]);
        return vc;
    }
};