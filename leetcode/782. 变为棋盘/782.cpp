class Solution {
public:
    int movesToChessboard(vector<vector<int>>& board) {
        int n = board.size(), rowSum = 0, colSum = 0, rowDiff = 0, colDiff = 0;

        for (int i = 0; i < n; i++)
        {
            /**
            ***һ�����ε��ĸ�����ֻ���������
            ***Ҫô�ĸ�0��Ҫô�ĸ�1��Ҫô����0����1
            ***��ô�ĸ����������һ��һ����0
            ***���������ж�ֻҪ������1��һ���ǲ��Եģ�ֱ�ӷ���-1
            **/
            for (int j = 0; j < n; j++)
            {
                if (board[0][0] ^ board[i][0] ^ board[i][j] ^ board[0][j])   return -1;
            }
        }
        for (int i = 0; i < n; i++)
        {
            colSum += board[i][0];
            rowSum += board[0][i];
            rowDiff += (board[0][i] == i % 2);
            colDiff += (board[i][0] == i % 2);
        }
        if (rowSum < n / 2 || rowSum >(n + 1) / 2)  return -1;
        if (colSum < n / 2 || colSum >(n + 1) / 2)  return -1;

        if (n % 2)
        {
            // n������������õ�ż������λ��
            if (colDiff % 2) colDiff = n - colDiff;
            if (rowDiff % 2) rowDiff = n - rowDiff;
        }
        else
        {
            // ����Ĭ���Ǹ�   1010... �Ƚ�
            // ������������Ϊ 0101... �Ȿ�������ȷ����������
            colDiff = std::min(n - colDiff, colDiff);
            rowDiff = std::min(n - rowDiff, rowDiff);
        }
        return (colDiff + rowDiff) / 2;
    }
};