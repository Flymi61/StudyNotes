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
     * @param pRoot TreeNode��
     * @return TreeNode��
     */
    TreeNode* Mirror(TreeNode* pRoot) {
        // write code here
        if (pRoot == nullptr)
            return nullptr;
        std::swap(pRoot->left, pRoot->right);
        Mirror(pRoot->left);
        Mirror(pRoot->right);
        return pRoot;
    }
};