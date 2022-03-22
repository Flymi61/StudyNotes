class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param array int����vector
     * @return int����vector
     */
    vector<int> FindGreatestSumOfSubArray(vector<int>& array) {
        // write code here
        int cur = 0;
        int sum = array[0];
        vector<int> vcur;
        vector<int> vsum;
        for (auto e : array)
        {
            cur += e;
            vcur.push_back(e);
            if (sum < cur)
            {
                sum = cur;
                vsum = vcur;
            }
            if (sum <= cur && vsum.size() < vcur.size())
            {
                vsum = vcur;
            }
            if (cur < 0)
            {
                vcur.resize(0);
                cur = 0;
            }
        }
        return vsum;
    }
};