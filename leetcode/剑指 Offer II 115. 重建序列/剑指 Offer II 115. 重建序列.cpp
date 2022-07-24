class Solution {
public:
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
        int n = nums.size();
        //����ͼ
        vector<unordered_set<int>> graph(n + 1);
        vector<int> degree(n + 1, 0);
        for (auto& sequence : sequences)
        {
            int sz = sequence.size();
            for (int i = 0; i < sz - 1; i++)
            {
                graph[sequence[i]].insert(sequence[i + 1]);
                degree[sequence[i + 1]] += 1;
            }
        }
        //�洢���Ϊ0�ĵ�
        queue<int> q;
        for (int i = 1; i <= n; i++)
        {
            if (degree[i] == 0)
                q.emplace(i);
        }
        while (!q.empty())
        {
            if (q.size() > 1)
                return false;
            int index = q.front();
            q.pop();
            for (auto& e : graph[index])
            {
                degree[e] -= 1;
                if (degree[e] == 0)
                    q.emplace(e);
            }
        }
        return true;
    }
};