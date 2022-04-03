class Solution {
public:
    int getValue(char ch)
    {
        switch (ch) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
        }
    }

    int romanToInt(string s) {
        int number = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int flag = 1;
            if (i + 1 < s.size() && getValue(s[i]) < getValue(s[i + 1]))
                flag = -1;
            number += getValue(s[i]) * flag;
        }
        return number;
    }
};