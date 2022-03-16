class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param number long������
     * @return long������
     */
     //3 ����
    long long pow(long long number)
    {
        if (number == 0)
            return 1;
        if (number == 1)
            return 3;
        long long pow_result = 1;

        pow_result = pow(number / 2);
        pow_result %= 998244353;
        pow_result *= pow_result;
        pow_result %= 998244353;
        if (number % 2 == 1)
        {
            pow_result *= 3;
            pow_result %= 998244353;
        }
        return pow_result;
    }
    long long cutRope(long long number) {
        // write code here
        if (number <= 3)
            return number - 1;
        //number %= 998244353;
        long long count_2 = 0;
        long long count_3 = 0;
        count_3 = number / 3;
        if (number % 3 == 2)
            count_2++;
        else if (number % 3 == 1)
        {
            count_3--;
            count_2 += 2;
        }
        long long product = pow(count_3);
        while (count_2--)
        {
            product *= 2;
            product = product % 998244353;
        }
        return product;
    }
};