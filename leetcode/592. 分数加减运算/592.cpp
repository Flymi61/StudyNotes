class Solution {
public:
    string fractionAddition(string expression) {
        int sz = expression.size();
        long long numerator = 0;   //����
        long long denominator = 1; //��ĸ
        int cur = 0;
        while (cur < sz)
        {
            //��ȡ����
            int p = cur;
            while (cur < sz && expression[cur] != '/')
            {
                cur++;
            }
            long long _numerator = stoll(string(expression.begin() + p, expression.begin() + cur));
            //��ȡ��ĸ
            p = ++cur;
            while (cur < sz && expression[cur] != '+' && expression[cur] != '-')
            {
                cur++;
            }
            long long _denominator = stoll(string(expression.begin() + p, expression.begin() + cur));
            numerator = numerator * _denominator + denominator * _numerator;
            denominator *= _denominator;
        }
        if (numerator == 0)
            return "0/1";
        long long GCD = gcd(abs(numerator), denominator);
        return to_string(numerator / GCD) + "/" + to_string(denominator / GCD);
    }
};