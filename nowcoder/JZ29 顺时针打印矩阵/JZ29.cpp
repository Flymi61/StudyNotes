class Solution {
public:

    vector<int> ClockwisePrint(vector<vector<int> >& matrix)
    {
        vector<int> storage;
        int row = 0;
        int col = 0;
        while (matrix.size() >= 2 * row + 1 && matrix[0].size() >= 2 * col + 1)
        {
            int startx = row;
            int starty = col;
            //������
            while (starty < matrix[0].size() - col - 1)
            {
                storage.push_back(matrix[startx][starty]);
                starty++;
            }
            //��������
            while (startx < matrix.size() - row - 1)
            {
                storage.push_back(matrix[startx][starty]);
                startx++;
            }
            //���ҵ���
            while (starty > col && startx != row)
            {
                storage.push_back(matrix[startx][starty]);
                starty--;
            }
            //���¶���
            while (startx > row && starty != matrix[0].size() - col - 1)
            {
                storage.push_back(matrix[startx][starty]);
                startx--;
            }
            if (starty == matrix[0].size() - col - 1)
            {
                storage.push_back(matrix[startx][starty]);
            }
            row++;
            col++;
        }
        return storage;
    }

    vector<int> printMatrix(vector<vector<int> > matrix) {
        if (matrix.size() == 0)
            return vector<int>();
        return ClockwisePrint(matrix);
    }
};