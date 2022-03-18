/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param root TreeNode��
     * @param sum int����
     * @return int����
     */
    int count = 0;
    void path(TreeNode* root, int sum)
    {
        if (root == nullptr)
            return;
        if (root->val == sum)
            count++;
        path(root->left, sum - root->val);
        path(root->right, sum - root->val);
    }
    int FindPath(TreeNode* root, int sum) {
        // write code here
        if (root == nullptr)
            return 0;
        path(root, sum);
        FindPath(root->left, sum);
        FindPath(root->right, sum);

        return count;
    }
};