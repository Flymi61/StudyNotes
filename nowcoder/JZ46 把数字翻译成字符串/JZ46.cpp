class Solution {
public:
    /**
     * ����
     * @param nums string�ַ��� ���ִ�
     * @return int����
     */
    int ResultCount(const string& nums, int index)
    {
        if (index >= nums.size() || nums[index] == '\0' || nums[index] == '0')
            return 0;
        //��ʾ��ʣ1��Ԫ��
        if (index + 1 >= nums.size())
            return 1;
        //��ǰ���ִ��ڵ���3��ֻ����һ�ֽ��
        if (nums[index] >= '3')
            return ResultCount(nums, index + 1);
        //Ϊ10��20������һ�ֽ��
        if (nums[index + 1] == '0')
            return index == nums.size() - 2 ? 1 : ResultCount(nums, index + 2);
        //Ϊ27/28/29����2�ض�����
        if (nums[index] == '2' && nums[index + 1] >= '7')
            return index == nums.size() - 2 ? 1 : ResultCount(nums, index + 2);
        if (index == nums.size() - 2)
            return 2;
        return  ResultCount(nums, index + 1) + ResultCount(nums, index + 2);
    }

    int solve(string nums) {
        // write code here
        return ResultCount(nums, 0);
    }
};