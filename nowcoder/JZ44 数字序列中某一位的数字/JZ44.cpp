class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param n int����
     * @return int����
     */
    int findNthDigit(int n) {
        // write code here
        if (n <= 9)
            return n;

        size_t max = 9;
        int stage = 1;
        size_t  prev = 0;
        int remainder = 0;
        int result;
        int D_value;
        while (max < n)
        {
            //����
            stage++;
            prev = max;
            max = max + 9 * stage * (size_t)pow(10, stage - 1);
        }
        //D_value ��ʾ��ǰһ�����������ֵ + 1���Ĳ�
        D_value = n - prev - 1;
        //remainder ��ʾ����
        remainder = D_value % stage;
        //������Ϊ0�����������ֵλ�ڵ�stageλ
        if (remainder == 0)
            result = D_value / (stage * size_t(pow(10, stage - 1))) + 1;
        //������Ϊ0������������ж��ǵ� stage - remaindeλ��
        //���ݲ�ֵ��ͨ��ȡģ���� % stage*10^(stage-remainder)ȡ����stage - 1λ
        else
            //result = (D_value / (stage * size_t(pow(10, stage - remainder - 1)))) % 10;
            result = (D_value % (stage * size_t(pow(10, stage - remainder)))) / (stage * size_t(pow(10, stage - remainder - 1)));
        //1000000000~1
        // 500000000~8
        return result;
    }
};