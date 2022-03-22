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
     * @param proot TreeNode��
     * @param k int����
     * @return int����
     */

    int number(TreeNode* proot, int& n, int k)
    {
        if (proot == nullptr)
        {
            return -1;
        }
        int num = number(proot->left, n, k);
        if (num != -1)
            return num;
        n++;
        if (n == k)
            return proot->val;
        num = number(proot->right, n, k);
        return num;
    }

    int KthNode(TreeNode* proot, int k) {
        // write code here
        int n = 0;
        return number(proot, n, k);
    }
};