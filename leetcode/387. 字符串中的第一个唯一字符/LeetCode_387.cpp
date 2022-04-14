class Solution {
public:
    int firstUniqChar(string s) {
        int count[256] = { 0 };
        for (size_t i = 0; i < s.size(); i++)
        {
            //���128����¼��Ӧ�ַ������ֵĴ�������128����¼��һ�γ��ֵ��±�
            size_t _n = s[i];
            if (count[_n] == 0)
            {
                count[_n + 128] = i;
            }
            count[_n] += 1;
        }
        //���±꿪ʼ����
        int p = -1;
        for (size_t i = 0; i < 128; i++)
        {
            if (count[i] == 1)
            {
                if (p == -1 || p > count[i + 128])
                {
                    p = count[i + 128];
                }
            }
        }
        return p;
    }
};