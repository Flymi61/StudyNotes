/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int dfs(TreeNode* root, TreeNode* parent)
    {
        if (!root)   return 0;
        int left = dfs(root->left, root);
        int right = dfs(root->right, root);
        graph[root->val][parent->val] = 1;
        graph[parent->val][root->val] = 1;
        visited[root->val] = false;
        return 1 + left + right;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int _k) {
        // ͼ--��Դ���·��
        int n = 1 + dfs(root->left, root) + dfs(root->right, root);
        visited[target->val] = true;
        while (--n)
        {
            graph[target->val][target->val] = 0x7fffffff;
            int ret = target->val;
            for (auto& [k, v] : graph[target->val])
            {
                // Ѱ�����·���ڵ�
                if (visited[k] == false)
                {
                    if (v < graph[target->val][ret])  ret = k;
                }
            }
            // �����ɳ�
            for (auto& [k, v] : graph[ret])
            {
                if (graph[target->val].count(k) == 0 ||
                    graph[target->val][k] > graph[target->val][ret] + graph[ret][k])
                {
                    graph[target->val][k] = graph[target->val][ret] + graph[ret][k];
                }
            }
            visited[ret] = true;
        }
        graph[target->val][target->val] = 0;
        vector<int> ans;
        for (auto& [k, v] : graph[target->val])
        {
            if (v == _k) ans.push_back(k);
        }
        return ans;
    }
private:
    unordered_map<int, map<int, int>> graph;
    unordered_map<int, bool> visited;
};