class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param str string�ַ���
     * @return bool������
     */
    bool isNumeric(string str) {
        // write code here
        int flag_dot = 0;
        int flag_scientific = 0;
        string s;
        for (auto e : str)
        {
            if (e == ' ')
                continue;
            s += e;
        }
        str = s;
        if (s == "")
            return false;
        for (int pos = 0; pos < str.size(); pos++)
        {
            if (str[pos] == '.')
            {
                //���ұ�����һ������
                if ((pos && (str[pos - 1] >= '0' && str[pos - 1] <= '9')) || ((str[pos + 1] >= '0' && str[pos + 1] <= '9')))
                {
                    //�������� e/E ����
                    if (flag_scientific || flag_dot)
                        return false;
                    flag_dot++;
                }
                else
                    return false;
            }
            else if (str[pos] == '+' || str[pos] == '-')
            {
                if (pos == 0 || str[pos - 1] == 'e' || str[pos - 1] == 'E')
                {
                    if (str[pos + 1] >= '0' && str[pos + 1] <= '9')
                        continue;
                    else
                    {
                        if (str[pos + 1] == '.')
                        {
                            if (flag_scientific)
                                return false;
                            if (str[pos + 2] >= '0' && str[pos + 2] <= '9')
                                continue;
                            else
                                return false;
                        }
                        return false;
                    }
                }
                else
                    return false;
            }
            else if (str[pos] == 'e' || str[pos] == 'E')
            {
                if (flag_scientific)
                    return false;
                //����eǰ��
                if (pos && str[pos - 1] >= '0' && str[pos - 1] <= '9')
                    ;// continue;
                else if (pos && str[pos - 1] == '.')
                {
                    if (pos >= 2 && str[pos - 2] >= '0' && str[pos - 2] <= '9')
                        ;//continue;
                    else
                        return false;
                }
                else
                    return false;
                //����e����
                if (str[pos + 1] == '+' || str[pos + 1] == '-' || (str[pos + 1] >= '0' && str[pos + 1] <= '9'))
                    ;
                else
                    return false;
                flag_scientific++;
            }
            else if (str[pos] >= '0' && str[pos] <= '9')
            {
                continue;
            }
            else {
                return false;
            }

        }
        return true;
    }
};