class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int flag = 0;
        vector<int> num;
        num.resize(2);
        num[0] = num[1] = 0;
        //�ҳ����Ľ��
        for (size_t i = 0; i < nums.size(); i++)
        {
            flag ^= nums[i];
        }
        //�ض���һλΪ1�����ҳ����һ��1����λ��
        while (flag % 2 != 1 && flag % 2 != -1)
        {
            num[0]++;
            flag = flag >> 1;
        }
        //����λ��Ϊ0
        flag = 1 << num[0];
        num[0] = 0;
        //����Ԫ���У���λ����ֻ�����֣�������������һ�ε�Ԫ�أ����Ҳ�ز���ͬ
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (nums[i] & flag)
            {
                num[0] = nums[i] ^ num[0];
            }
            else
            {
                num[1] = nums[i] ^ num[1];
            }
        }
        return num;
    }
};