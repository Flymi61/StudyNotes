class Solution {
public:
    int Count(vector<vector<int>>& count, int threshold, int rows, int cols)
    {
        //�ݹ����
        if (rows >= count.size() || cols >= count[0].size() || count[rows][cols] == 0 || (rows / 10 + rows % 10 + cols / 10 + cols % 10) > threshold)
            return 0;
        count[rows][cols] = 0;
        return 1 + Count(count, threshold, rows, cols + 1)
            + Count(count, threshold, rows + 1, cols);
    }

    int movingCount(int threshold, int rows, int cols) {
        //��ά���鴴��
        vector<vector<int>> count;
        count.resize(rows);
        for (size_t i = 0; i < rows; i++)
        {
            count[i].resize(cols);
        }
        //��ֵ
        for (size_t i = 0; i < rows; i++)
        {
            for (size_t j = 0; j < cols; j++)
            {
                count[i][j] = 1;
            }
        }
        return Count(count, threshold, 0, 0);
    }
};