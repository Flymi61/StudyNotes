/*class Solution {
        //����һ������ѭ��
public:
    double Power(double base, int exponent) {
        double end = 1;
        if(exponent > 0)
        {
            while(exponent--)
            {
                end = end * base;
            }

        }
        else
        {
            while(exponent++)
            {
                end = end / base;
            }
        }
        return end;
    }
};*/
/*class Solution {
    //���������ݹ�
public:
    double Power(double base, int exponent) {
        if(exponent > 0)
            return  Power(base,exponent - 1) * base;
        else if(exponent < 0)
            return  Power(base,exponent - 1) / base;
        else
            return 1;
    }
};*/
class Solution {
    //��������logN
public:
    double Power(double base, int exponent) {
        double result = 1;
        for (int i = exponent; i != 0; i /= 2)
        {
            if (i & 1)
                result *= base;
            base *= base;
        }
        if (exponent < 0)
            result = 1 / result;
        return result;
    }
};