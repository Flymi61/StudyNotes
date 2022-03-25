class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param s string�ַ���
     * @return int����
     */
    int lengthOfLongestSubstring(string s) {
        // write code here
        int index = 0;
        int cur = 0;
        int len = 0;
        unordered_map<char, int> unmap;
        while (cur < s.size())
        {
            unmap[s[cur]] += 1;
            if (unmap[s[cur]] > 1)
            {
                if (len < cur - index)
                {
                    len = cur - index;
                }
                while (unmap[s[cur]] > 1)
                {
                    unmap[s[index]] -= 1;
                    index++;
                }
            }
            cur++;
        }
        if (len < cur - index)
        {
            len = cur - index;
        }
        return len;
    }
};