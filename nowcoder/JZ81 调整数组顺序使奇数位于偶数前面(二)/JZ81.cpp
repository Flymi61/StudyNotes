class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param array int����vector
     * @return int����vector
     */
    vector<int> reOrderArrayTwo(vector<int>& array) {
        // write code here
        for (size_t i = 0; i < array.size(); i++)
        {
            if (array[i] % 2 == 0)
            {
                int j = i + 1;
                while (j < array.size() && array[j] % 2 == 0)
                {
                    j++;
                }
                if (j == array.size())
                    break;
                else
                    std::swap(array[i], array[j]);
            }
        }
        return array;
    }
};