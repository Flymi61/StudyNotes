class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //����32��С�����飬���Լ�¼ÿ��������λ1�ĸ���
        int arr[32] = { 0 };

        for (size_t i = 0; i < nums.size(); i++)
        {
            //ÿ��Ԫ������ͳ��
            for (size_t j = 0; j < 32; j++)
            {
                //ͳ��ÿ��������λ1����Ŀ
                arr[j] += (nums[i] >> j) & 1;
            }
        }
        //ÿ��Ԫ�� % 3 ����������Ϊ����Ԫ�ض�Ӧ������λ�����֣� 0 /  1��
        for (size_t j = 0; j < 32; j++)
        {
            arr[j] %= 3;
        }
        //������ʱ��������������תΪ int 
        int ret = 0;
        for (size_t j = 0; j < 32; j++)
        {
            ret = ret ^ (arr[j] << j);
        }
        return ret;
    }
};