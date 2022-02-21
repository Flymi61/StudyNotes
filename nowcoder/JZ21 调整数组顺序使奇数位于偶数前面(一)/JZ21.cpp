class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param array int����vector
     * @return int����vector
     */
    vector<int> reOrderArray(vector<int>& array) {
        // write code here 
        //ֱ�Ӳ���˼��
        int pos = 0;
        while (pos < array.size())
        {
            if (array[pos] % 2 == 1)
            {
                int cur = pos;
                int tmp = array[pos];
                while (cur > 0 && array[cur - 1] % 2 == 0)
                {
                    array[cur] = array[cur - 1];
                    cur--;
                }
                array[cur] = tmp;
            }
            pos++;
        }
        return array;
    }
};