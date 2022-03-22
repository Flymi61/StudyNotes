/*class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param numbers int����vector
     * @return int����
     */
     /*    int duplicate(vector<int>& numbers) {
             // write code here
             //����˼·������
             std::sort(numbers.begin(), numbers.end());
             for(size_t i = 0; i < numbers.size(); ++i)
             {
                 if(numbers[i] == numbers[i + 1])
                     return numbers[i];
             }
             return -1;
         }
     };*/
class Solution {
public:
    int duplicate(vector<int>& numbers) {
        //
        vector<int> count;
        count.resize(numbers.size());
        for (auto& e : count)
        {
            e = 0;
        }
        for (const auto e : numbers)
        {
            count[e] += 1;
            if (count[e] >= 2)
                return e;
        }
        return -1;
    }
};
