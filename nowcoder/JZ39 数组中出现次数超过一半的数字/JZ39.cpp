//����һ
/*class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        //����32��С�����飬���Լ�¼ÿ��������λ1�ĸ���
        int arr[32] = { 0 };
        for(size_t i = 0; i < numbers.size(); i++)
        {
            //ÿ��Ԫ������ͳ��
            for(size_t j = 0; j < 32; j++)
            {
                //ͳ��ÿ��������λ1����Ŀ
                arr[j] += (numbers[i] >> j) & 1;
            }
        }
        for(size_t j = 0; j < 32; j++)
        {
            if(arr[j] > numbers.size() / 2)
            {
                arr[j] = 1;
            }
            else
            {
                arr[j] = 0;
            }
        }
        //������ʱ��������������תΪ int
        int ret = 0;
        for(size_t j = 0; j < 32; j++)
        {
            ret = ret ^ (arr[j] << j);
        }
        return ret;
    }
};*/

//������
/*class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        std::sort(numbers.begin(),numbers.end());
        return numbers[numbers.size() / 2];
        //�м�Ԫ�رض�Ϊ����Ԫ��
    }
};*/

//������
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int count = 0;
        int pti = numbers[0];
        for (size_t i = 1; i < numbers.size(); i++)
        {
            if (count == 0)
            {
                pti = numbers[i];
            }
            if (numbers[i] == pti)
            {
                count++;
            }
            else
            {
                count--;
            }
        }
        return pti;
    }
};