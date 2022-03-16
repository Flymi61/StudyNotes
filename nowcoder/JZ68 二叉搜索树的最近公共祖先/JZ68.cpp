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
     * @param p int����
     * @param q int����
     * @return int����
     */
    int lowestCommonAncestor(TreeNode* root, int p, int q) {
        // write code here
        if (root == nullptr || root->val == p || root->val == q)
            return root->val;
        if (q < p)
            std::swap(p, q);
        if (root->val > p && root->val < q)
            return root->val;
        if (root->val < q)
            return lowestCommonAncestor(root->right, p, q);
        return lowestCommonAncestor(root->left, p, q);
    }
};