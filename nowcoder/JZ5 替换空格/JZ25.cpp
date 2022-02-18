class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param s string�ַ���
     * @return string�ַ���
     */
    string replaceSpace(string s) {
        // write code here
        int count = 0;
        int j = 0;
        while (j < s.size())
        {
            if (s[j] == ' ')
                count++;
            j++;
        }
        int newlength = s.size() + 2 * count + 1;
        int oldlength = s.size() + 1;
        s.resize(newlength);
        while (oldlength >= 0 && newlength >= 0)
        {
            if (s[oldlength] == ' ')
            {
                s[newlength--] = '0';
                s[newlength--] = '2';
                s[newlength--] = '%';
                oldlength--;
            }
            else
            {
                s[newlength--] = s[oldlength--];
            }
        }
        return s;
    }
};