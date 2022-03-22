class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param grid int����vector<vector<>>
     * @return int����
     */
    int Sum(vector<vector<int> >& grid, vector<vector<int> >& count, int x, int y)
    {
        //��������֮һ��������ݹ�
        if (x == count.size() - 1 || y == count[0].size() - 1 || count[x][y] > 0)
            return count[x][y];
        int max1 = Sum(grid, count, x + 1, y);
        int max2 = Sum(grid, count, x, y + 1);
        count[x][y] = max1 > max2 ? grid[x][y] + max1 : grid[x][y] + max2;
        //count[x][y] += count[x + 1][y] > count[x][y + 1] ? count[x + 1][y] + grid[x][y] : count[x][y + 1] + grid[x][y];
        return count[x][y];
    }

    int maxValue(vector<vector<int> >& grid) {
        // write code here
        //�ռ任ʱ��
        //������ά���飬����ֵΪ 0
        vector<vector<int> > count;
        count.resize(grid.size() + 1);
        for (auto& e : count)
        {
            e.resize(grid[0].size() + 1);
            for (auto& ee : e)
            {
                ee = 0;
            }
        }
        //����
        return Sum(grid, count, 0, 0);
    }
};