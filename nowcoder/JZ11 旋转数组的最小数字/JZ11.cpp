class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        //���ö��ֲ��ҵķ�ʽ�����ж�λ
        if (rotateArray.size() == 0)
            return 0;
        int left = 0;
        int right = rotateArray.size() - 1;
        int mid = 0;
        while (rotateArray[left] >= rotateArray[right])
        {
            if (left + 1 == right)
            {
                mid = right;
                break;
            }
            mid = left + ((right - left) >> 1);
            //��ʱ�޷�ȷ��
            if (rotateArray[left] == rotateArray[mid] &&
                rotateArray[left] == rotateArray[right])
            {
                for (size_t i = left; i < right; i++)
                {
                    if (rotateArray[i] != rotateArray[i + 1])
                        return rotateArray[i + 1];
                }
            }
            //λ������
            if (rotateArray[left] > rotateArray[mid])
                right = mid;
            //λ���Ұ��
            else
                left = mid;
        }
        return rotateArray[mid];
    }
};