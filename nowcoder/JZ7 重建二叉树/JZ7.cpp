/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    TreeNode* Construct(vector<int>::iterator begin_prev, vector<int>::iterator end_prev,
        vector<int>::iterator begin_in, vector<int>::iterator end_in)
    {
        if (begin_prev == end_prev || begin_in == end_in)
            return nullptr;
        TreeNode* _root = new TreeNode(begin_prev[0]);
        _root->left = nullptr;
        _root->right = nullptr;
        //�ҵ���һ�����ڵ�
        vector<int>::iterator root_in = begin_in;
        while (root_in != end_in && *root_in != begin_prev[0])
        {
            ++root_in;
        }
        //����������
        int lenth = root_in - begin_in;
        if (lenth)
        {
            _root->left = Construct(begin_prev + 1, begin_prev + lenth + 1, begin_in, begin_in + lenth);
        }
        //����������
        _root->right = Construct(begin_prev + lenth + 1, end_prev, begin_in + lenth + 1, end_in);
        return _root;
    }

    TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
        return Construct(pre.begin(), pre.end(), vin.begin(), vin.end());
    }
};