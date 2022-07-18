class Solution {
private:
    static constexpr int d[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
public:
    int containVirus(vector<vector<int>>& isInfected) {
        struct pair_hash
        {
            std::size_t operator() (const std::pair<int, int>& pair) const
            {
                return std::hash<int>()(pair.first) ^ std::hash<int>()(pair.second);
            }
        };
        int rows = isInfected.size();
        int cols = isInfected[0].size();
        int ans = 0;
        while (true)
        {
            //��¼����������Ⱦ��������ڷǸ�Ⱦ��
            vector<std::unordered_set<pair<int, int>, pair_hash>> neibor;
            //��¼����������Ⱦ��������ķ���ǽ���������±�һһ��Ӧ
            vector<int> firewalls;
            //��ȡδ��������ǽ��������Ⱦ����
            for (int x = 0; x < rows; x++)
            {
                for (int y = 0; y < cols; y++)
                {
                    if (isInfected[x][y] == 1)
                    {
                        //���Դ洢���ڸ�Ⱦ��
                        queue<pair<int, int>> q;
                        //���Դ洢���ڷǸ�Ⱦ��
                        std::unordered_set<pair<int, int>, pair_hash> n0;
                        //��¼ÿһ������������ķ���ǽ����
                        int firewall = 0;
                        //Ϊÿ��������Ⱦ������б��
                        int id = neibor.size() + 1;
                        q.push(make_pair(x, y));
                        //BFS  
                        while (!q.empty())
                        {
                            auto cur = q.front();
                            q.pop();
                            //���и�ֵ������ʾ�ѷ���
                            isInfected[cur.first][cur.second] = -id;
                            //������������
                            for (int n = 0; n < 4; n++)
                            {
                                int i = cur.first + d[n][0];
                                int j = cur.second + d[n][1];
                                if (i >= 0 && i < rows && j >= 0 && j < cols)
                                {
                                    if (isInfected[i][j] == 1)
                                    {
                                        //Ϊ1��ʾ�����򱻸�Ⱦ��δ������
                                        q.push(make_pair(i, j));
                                        //��ǡ�����ֹ�ظ����
                                        isInfected[i][j] = -id;
                                    }
                                    else if (isInfected[i][j] == 0)
                                    {
                                        //Ϊ0��ʾ������δ��Ⱦ
                                        firewall += 1;
                                        //�����λ����Ϣ�����������Ⱦ�Լ��������ȴ���
                                        n0.insert(make_pair(i, j));
                                    }
                                }
                            }
                        }
                        //�洢��������������ķ���ǽ��Ŀ
                        firewalls.push_back(firewall);
                        //�洢�ø�Ⱦ����Ӱ���λ����Ϣ
                        neibor.push_back(n0);
                    }
                }
            }
            //��ȡӰ����������δ��������ǽ�ĸ�Ⱦ����
            if (neibor.size() == 0)
                break;
            int idx = 0;
            int sz = neibor.size();
            for (int i = 0; i < sz; i++)
            {
                if (neibor[i].size() > neibor[idx].size())
                    idx = i;
            }
            ans += firewalls[idx];
            //���ò���
            for (int x = 0; x < rows; x++)
            {
                for (int y = 0; y < cols; y++)
                {
                    if (isInfected[x][y] < 0)
                    {
                        if (isInfected[x][y] == -idx - 1)
                            isInfected[x][y] = 2;
                        else
                            isInfected[x][y] = 1;
                    }
                }
            }
            //���и�Ⱦ����
            for (int i = 0; i < sz; i++)
            {
                if (i != idx)
                {
                    for (auto& idx : neibor[i])
                    {
                        isInfected[idx.first][idx.second] = 1;
                    }
                }
            }
        }
        return ans;
    }
};