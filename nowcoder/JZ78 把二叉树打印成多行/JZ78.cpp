/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    vector<vector<int> > vc;
    void Level_order(TreeNode* root)
    {
        if (root == nullptr)
            return;
        vector<int> vvc;
        queue<TreeNode*> qroot;
        qroot.push(root);
        //size ���Լ�¼ÿ��Ԫ�ظ���
        int size = 1;
        while (!qroot.empty())
        {
            //count ������¼�����ڵ���Ŀ
            int count = 0;
            while (size)
            {
                //ÿ��Ԫ����vector��ͬʱ������һ��ڵ�
                if (qroot.front()->left)
                {
                    qroot.push(qroot.front()->left);
                    count++;
                }
                if (qroot.front()->right)
                {
                    qroot.push(qroot.front()->right);
                    count++;
                }
                vvc.push_back(qroot.front()->val);
                qroot.pop();
                size--;
            }
            //ÿ����һ����ά����
            vc.push_back(vvc);
            //�ÿգ��Ա�����һ��
            vvc.resize(0);
            //size ������һ��ڵ���
            size += count;
        }
    }


    vector<vector<int> > Print(TreeNode* pRoot) {
        Level_order(pRoot);
        return vc;
    }

};