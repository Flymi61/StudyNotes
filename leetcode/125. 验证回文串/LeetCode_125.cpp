class Solution {
public:
    //�ж��Ƿ�Ϊ���ֻ���ĸ
    bool is(char s)
    {
        if ((s >= 'A' && s <= 'Z') || (s >= '0' && s <= '9'))
            return true;
        return false;
    }

    bool isPalindrome(string s)
    {
        int i = 0;
        int j = s.size() - 1;
        //�Ƚ���ȫ��תΪ��д
        for (auto& e : s)
        {
            if (e >= 'a' && e <= 'z')
            {
                e -= 32;
            }
        }

        while (i < j)
        {
            while (i < j && (!is(s[i])))
            {
                i++;
            }
            while (i < j && (!is(s[j])))
            {
                j--;
            }
            if (i < j)
            {
                if (s[i] != s[j])
                {
                    return false;
                }
            }
            i++;
            j--;
        }
        return true;
    }
};