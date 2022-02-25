class Solution {
public:
    string ReverseSentence(string str) {
        //������ת��
        std::reverse(str.begin(), str.end());
        string::iterator begin = str.begin();
        string::iterator end = str.begin();
        while (*end != '\0')
        {
            if (*end == ' ')
            {
                std::reverse(begin, end);
                begin = end + 1;
            }
            end++;
        }
        std::reverse(begin, end);
        return str;
    }
};