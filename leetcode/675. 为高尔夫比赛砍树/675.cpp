class Solution {
public:
    /*int bfs(vector<vector<int>>& forest, pair<int, int> start, pair<int, int> target)
    {
        int rows = forest.size();
        int cols = forest[0].size();
        int step = 0;
        set<pair<int, int>> visited;
        visited.insert(start);
        queue<pair<int, int>> q;
        q.push(start);
        //vector<vector<bool>> visited(row, vector<bool>(col, false));
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                pair<int, int> cur = q.front();
                q.pop();
                //��Ч�ڵ�
                if(cur.first == target.first && cur.second == target.second)
                    return step;
                //��Ч���ڽڵ�
                if(cur.first - 1 >= 0 && forest[cur.first - 1][cur.second] > 0 &&
                visited.find(make_pair(cur.first - 1, cur.second)) == visited.end())
                {
                    q.push(make_pair(cur.first - 1, cur.second));
                    visited.insert(make_pair(cur.first - 1, cur.second));
                }
                if(cur.second - 1 >= 0 && forest[cur.first][cur.second - 1] > 0 &&
                visited.find(make_pair(cur.first, cur.second - 1)) == visited.end())
                {
                    q.push(make_pair(cur.first, cur.second - 1));
                    visited.insert(make_pair(cur.first, cur.second - 1));
                }
                if(cur.second + 1 < cols && forest[cur.first][cur.second + 1] > 0 &&
                visited.find(make_pair(cur.first, cur.second + 1)) == visited.end())
                {
                    q.push(make_pair(cur.first, cur.second + 1));
                    visited.insert(make_pair(cur.first, cur.second + 1));
                }
                if(cur.first + 1 < rows && forest[cur.first + 1][cur.second] > 0 &&
                visited.find(make_pair(cur.first + 1, cur.second)) == visited.end())
                {
                    q.push(make_pair(cur.first + 1, cur.second));
                    visited.insert(make_pair(cur.first + 1, cur.second));
                }
            }
            step++;
        }
        return -1;
    }*/
    int bfs(vector<vector<int>>& forest, pair<int, int> start, pair<int, int> target)
    {
        int rows = forest.size();
        int cols = forest[0].size();
        int step = 0;
        //set<pair<int, int>> visited;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        visited[start.first][start.second] = true;
        queue<pair<int, int>> q;
        q.push(start);
        while (!q.empty())
        {
            int sz = q.size();
            while (sz--)
            {
                pair<int, int> cur = q.front();
                q.pop();
                //��Ч�ڵ�
                if (cur.first == target.first && cur.second == target.second)
                    return step;
                //��Ч���ڽڵ�
                //visited.find(make_pair(cur.first - 1, cur.second)) == visited.end())  
                if (cur.first - 1 >= 0 && forest[cur.first - 1][cur.second] > 0 &&
                    visited[cur.first - 1][cur.second] == false)
                {
                    q.push(make_pair(cur.first - 1, cur.second));
                    //visited.insert(make_pair(cur.first - 1, cur.second));
                    visited[cur.first - 1][cur.second] = true;
                }
                if (cur.second - 1 >= 0 && forest[cur.first][cur.second - 1] > 0 &&
                    visited[cur.first][cur.second - 1] == false)
                    //visited.find(make_pair(cur.first, cur.second - 1)) == visited.end())
                {
                    q.push(make_pair(cur.first, cur.second - 1));
                    visited[cur.first][cur.second - 1] = true;
                    //visited.insert(make_pair(cur.first, cur.second - 1));
                }
                if (cur.second + 1 < cols && forest[cur.first][cur.second + 1] > 0 &&
                    visited[cur.first][cur.second + 1] == false)
                    //visited.find(make_pair(cur.first, cur.second + 1)) == visited.end())
                {
                    q.push(make_pair(cur.first, cur.second + 1));
                    visited[cur.first][cur.second + 1] = true;
                    //visited.insert(make_pair(cur.first, cur.second + 1));
                }
                if (cur.first + 1 < rows && forest[cur.first + 1][cur.second] > 0 &&
                    visited[cur.first + 1][cur.second] == false)
                    //visited.find(make_pair(cur.first + 1, cur.second)) == visited.end())
                {
                    q.push(make_pair(cur.first + 1, cur.second));
                    //visited.insert(make_pair(cur.first + 1, cur.second));
                    visited[cur.first + 1][cur.second] = true;
                }
            }
            step++;
        }
        return -1;
    }

    int cutOffTree(vector<vector<int>>& forest) {
        map<int, pair<int, int>> order;
        int rows = forest.size();
        int cols = forest[0].size();
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (forest[i][j] > 1)
                    order[forest[i][j]] = make_pair(i, j);
            }
        }
        int step = 0;
        pair<int, int> pos = make_pair(0, 0);
        for (auto e : order)
        {
            int res = bfs(forest, pos, e.second);
            if (res == -1)
                return -1;
            forest[e.second.first][e.second.second] = 1;
            step += res;
            pos = e.second;
        }
        return step;
    }
};




/*
BFS ģ��

ģ��һ��
�������Ҫȷ����ǰ����������һ�㣬ֻ��Ҫ���������нڵ�Ϳ���ʱ��

BFS ģ�����£�


while queue ���գ�
    cur = queue.pop()
    if cur ��Ч��δ�����ʹ���
        ���д���
    for �ڵ� in cur ���������ڽڵ㣺
        if �ýڵ���Ч��
            queue.push(�ýڵ�)
ģ�����
���Ҫȷ����ǰ����������һ�㣬��Ҫ֪�������ƶ�����ʱ��BFS ģ�����¡�

���������� level ��ʾ��ǰ�������������е���һ���ˣ�Ҳ�������Ϊ��һ��ͼ�У������Ѿ����˶��ٲ��ˡ�size ��ʾ�ڵ�ǰ�������ж��ٸ�Ԫ�أ�Ҳ���Ƕ����е�Ԫ���������ǰ���ЩԪ��һ���Ա����꣬���ѵ�ǰ�������Ԫ�ض���������һ����


level = 0
while queue ���գ�
    size = queue.size()
    while (size --) {
        cur = queue.pop()
        if cur ��Ч��δ�����ʹ���
            ���д���
        for �ڵ� in cur���������ڽڵ㣺
            if �ýڵ���Ч��
                queue.push(�ýڵ�)
    }
    level ++;

*/



