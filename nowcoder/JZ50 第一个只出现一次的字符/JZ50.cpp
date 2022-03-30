class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        //��һ��Ϊ�������ڶ���Ϊ�±�
        map<char, pair<int, int>> fi;
        int index = 0;
        while (index < str.size())
        {
            fi[str[index]].first += 1;
            if (fi[str[index]].first == 1)
                fi[str[index]].second = index;
            index++;
        }
        int suffix = -1;
        for (auto e : fi)
        {
            //����Ϊ1
            if (e.second.first == 1)
            {
                if (suffix == -1 || e.second.second < suffix)
                    suffix = e.second.second;
            }
        }
        return suffix;
    }
};