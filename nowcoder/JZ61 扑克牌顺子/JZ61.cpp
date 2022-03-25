class Solution {
public:
    bool IsContinuous(vector<int> numbers) {
        std::sort(numbers.begin(), numbers.end());
        //�ų�0
        int index = 0;
        int i = 0;
        while (numbers[index] == 0)
        {
            index++;
            if (index < 4 && numbers[index] != 0 && numbers[index] == numbers[index + 1])
                return false;
        }
        //�ж��ظ���
        i = index;
        while (i < 4)
        {
            if (numbers[i] == numbers[i + 1])
                return false;
            i++;
        }
        //�ж��Ƿ���Ϊ˳��
        if (numbers[4] - numbers[index] > 4)
            return false;
        return true;
    }
};